#ifndef MESSAGE_INL
#define MESSAGE_INL

#include <gamelib/messages/Message.hpp>

#include <gamelib/utils/Split.hpp>

struct MessageConversionException : public std::runtime_error {
	MessageConversionException()
	: std::runtime_error("Error: converting message types")
	{}
};

template <typename T>
Message::Message(std::shared_ptr<T> d)
: store(new Storage<T>(d))
{
	
}

template <typename T>
std::shared_ptr<T> Message::Get() {
	auto s = std::dynamic_pointer_cast<Storage<T>>(store);
	if (!s) {
		throw MessageConversionException();
	} else {
		return s->Get();
	}
}

MessageReceiver::MessageReceiver(std::string name)
: name(name)
{
	MessageRouter::RegisterReceiver(name, this);
}

MessageReceiver::~MessageReceiver()
{
	MessageRouter::UnregisterReceiver(name);
}

const std::string &MessageReceiver::GetName() {
	return name;
}

void MessageReceiver::SetParent(MessageReceiver *p) {
	parent = p;
}

void MessageReceiver::AddChild(MessageReceiver *child) {
	children.insert(std::make_pair(child->name, child));
	child->SetParent(this);
}

void MessageReceiver::Find(std::vector<std::string>::const_iterator it,
                           std::vector<std::string>::const_iterator end,
                           std::set<MessageReceiver*> &found) {
	if (it == end) {
		found.insert(this);
		return;
	}

	const std::string &s = *it;

	if (s == "..") {
		parent->Find(it + 1, end, found);
	} else {
		auto range = children.equal_range(s);

		auto cit  = std::get<0>(range);
		auto cend = std::get<1>(range);

		for (; cit != cend; ++cit) {
			std::get<1>(*cit)->Find(it + 1, end, found);
		}
	}
}

template <typename T>
void MessageReceiver::SendMessage(std::string name, std::string id, std::shared_ptr<T> t) {
	std::vector<std::string> locs;
	Utils::Split(name, locs, '/');

	std::set<MessageReceiver*> receivers;

	Find(locs.begin(), locs.end(), receivers);

	for (MessageReceiver *m : receivers) {
		MessageRouter::SendMessage(m, id, t);
	}
}

template <typename T>
void MessageRouter::SendMessage(MessageReceiver *to, std::string id, std::shared_ptr<T> t) {
	Message m(t);
	GetInstance().message_queue.push(
		std::make_tuple(
			to, id, m
		)
	);
}

void MessageRouter::FlushMessages() {
	while (!GetInstance().message_queue.empty()) {
		auto m = GetInstance().message_queue.front();
		MessageReceiver *to = std::get<0>(m);

		to->ReceiveMessage(
			std::get<1>(m),
			std::get<2>(m)
		);

		GetInstance().message_queue.pop();
	}
}

void MessageRouter::RegisterReceiver(std::string name, MessageReceiver *m) {
	if (GetInstance().receivers.count(name) == 0) {
		GetInstance().receivers[name] = m;
	}
}

void MessageRouter::UnregisterReceiver(std::string name) {
	GetInstance().receivers.erase(name);
}

MessageRouter &MessageRouter::GetInstance() {
	static MessageRouter m;
	return m;
}

#endif /* MESSAGE_INL */
