#include <abxy/messages/Message.hpp>

#include <abxy/util/Split.hpp>

MessageReceiver::MessageReceiver(std::string name)
: name(name)
, makes_level(true)
, real_child(nullptr)
{

}

MessageReceiver::MessageReceiver(MessageReceiver *real_child)
: name("passthrough")
, makes_level(false)
, real_child(real_child)
{

}

MessageReceiver::~MessageReceiver()
{

}

void MessageReceiver::SendMessage(std::string path, std::string id, Message m) {
	std::vector<std::string> locs;
	Util::Split(path, locs, '/');

	std::set<MessageReceiver*> receivers;

	Find(locs.begin(), locs.end(), receivers);

	for (MessageReceiver *receiver : receivers) {
		MessageQueue::AddMessageToQueue(receiver, id, m);
	}
}

void MessageReceiver::ReceiveMessage(std::string id, Message m) {

}

const std::string &MessageReceiver::GetName() {
	return name;
}

void MessageReceiver::SetParent(MessageReceiver *p) {
	parent = p;
}

void MessageReceiver::AddChild(MessageReceiver *child) {
	// Find the nearest child that should actually be a level
	while (!child->MakesLevel()) {
		child = child->GetRealChild();
	}

	// If this child makes a level, use it as the real child
	children.insert(std::make_pair(child->name, child));
	child->SetParent(this);
}

void MessageReceiver::RemoveChild(MessageReceiver *child) {
	auto range = children.equal_range(child->name);

	auto it = std::get<0>(range);
	auto end = std::get<1>(range);

	for(; it != end; ++it) {
		if (it->second == child) {
			children.erase(it);
			it->second->SetParent(nullptr);
			break;
		}
	}
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
		if (parent != nullptr) {
			parent->Find(it + 1, end, found);
		} else {
			Find(it + 1, end, found);
		}
	} else {
		auto range = children.equal_range(s);

		auto cit  = std::get<0>(range);
		auto cend = std::get<1>(range);

		for (; cit != cend; ++cit) {
			std::get<1>(*cit)->Find(it + 1, end, found);
		}
	}
}

void MessageQueue::AddMessageToQueue(MessageReceiver *to, std::string id, Message m) {
	GetInstance().message_queue.push(
		std::make_tuple(
			to, id, m
		)
	);
}

void MessageQueue::FlushMessageQueue() {
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

MessageQueue &MessageQueue::GetInstance() {
	static MessageQueue m;
	return m;
}
