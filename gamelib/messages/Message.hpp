#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <memory>
#include <map>
#include <queue>
#include <tuple>

class StorageBase {
	virtual void A() {}
};

template <typename T>
class Storage : public StorageBase {
	std::shared_ptr<T> data;
public:
	Storage(std::shared_ptr<T> d) : data(d) {}
	std::shared_ptr<T> Get() {
		return data;
	}
};

class Message {
	std::shared_ptr<StorageBase> store;
public:
	template <typename T>
	Message(T *d);

	template <typename T>
	std::shared_ptr<T> Get();
};

class MessageReceiver {
	std::string name;
public:
	MessageReceiver(std::string name);
	virtual ~MessageReceiver();

	virtual void ReceiveMessage(std::string id, Message m) = 0;
};

class MessageRouter {
	std::map<std::string, MessageReceiver*> receivers;

	std::queue<std::tuple<std::string, std::string, Message>> message_queue;

	MessageRouter() {}

	static MessageRouter &GetInstance();
public:
	template <typename T>
	static void SendMessage(std::string to, std::string id, T *t);
	static void FlushMessages();

	static void RegisterReceiver(std::string name, MessageReceiver *m);
	static void UnregisterReceiver(std::string name);
};

#endif /* MESSAGE_HPP */

