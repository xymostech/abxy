#ifndef MESSAGE_INL
#define MESSAGE_INL

#include <gamelib/messages/Message.hpp>

struct MessageConversionException : public std::runtime_error {
	MessageConversionException()
	: std::runtime_error("Error: converting message types")
	{}
};

template <typename T>
Message::Message(T *d)
: store(new Storage<T>(std::shared_ptr<T>(d)))
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

template <typename T>
void MessageRouter::SendMessage(std::string to, std::string id, T *t) {
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
		std::string to = std::get<0>(m);

		if (GetInstance().receivers.count(to) > 0) {
			GetInstance().receivers[to]->ReceiveMessage(
				std::get<1>(m),
				std::get<2>(m)
			);
		}

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

