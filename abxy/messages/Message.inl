#ifndef MESSAGE_INL
#define MESSAGE_INL

#include <abxy/messages/Message.hpp>

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

template <typename T>
void MessageReceiver::SendMessage(std::string path, std::string id, std::shared_ptr<T> t) {
	SendMessage(path, id, Message(t));
}

#endif /* MESSAGE_INL */

