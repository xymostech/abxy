#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <memory>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <set>

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
	Message(std::shared_ptr<T> d);

	template <typename T>
	std::shared_ptr<T> Get();
};

class MessageReceiver {
	std::string name;
	std::unordered_multimap<std::string, MessageReceiver*> children;
	MessageReceiver *parent;

	void SetParent(MessageReceiver *p);

	void Find(std::vector<std::string>::const_iterator it,
	          std::vector<std::string>::const_iterator end,
	          std::set<MessageReceiver*> &found);
protected:
	void AddChild(MessageReceiver *child);

	template <typename T>
	void SendMessage(std::string name, std::string id, std::shared_ptr<T> t);
public:
	MessageReceiver(std::string name);
	virtual ~MessageReceiver();

	const std::string &GetName();

	virtual void ReceiveMessage(std::string id, Message m);
};

class MessageRouter {
	std::queue<std::tuple<MessageReceiver*, std::string, Message>> message_queue;

	MessageRouter() {}

	static MessageRouter &GetInstance();
public:
	static void AddMessageToQueue(MessageReceiver*, std::string id, Message m);
	static void FlushMessageQueue();

	static void RegisterReceiver(std::string name, MessageReceiver *m);
	static void UnregisterReceiver(std::string name);
};

#include <gamelib/messages/Message.hpp>

#endif /* MESSAGE_HPP */

