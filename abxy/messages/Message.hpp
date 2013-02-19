#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <memory>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <set>
#include <string>
#include <stdexcept>

struct MessageConversionException : public std::runtime_error {
	MessageConversionException()
	: std::runtime_error("Error: converting message types")
	{}
};

/**
 * The base class for a generic storage class
 *
 * This shouldn't actually be allocated
 */
class StorageBase {
	/**
	 * This is just a virtual function to include RTTI for the StorageBase
	 * class
	 */
	virtual void A() {}
};

/**
 * This is a generic storage class, which stores a std::shared_ptr of whatever
 * type it is. It implements a Get function which returns the data.
 *
 * It is mainly used within the Message class to store message data, but could
 * be used anywhere else
 */
template <typename T>
class Storage : public StorageBase {
	/**
	 * The stored generic data
	 */
	std::shared_ptr<T> data;
public:
	/**
	 * The constructor must take a shared_ptr
	 */
	Storage(std::shared_ptr<T> d) : data(d) {}
	
	/**
	 * This function simply retrieves the stored data
	 * @return the stored data
	 */
	std::shared_ptr<T> Get() {
		return data;
	}
};

/**
 * This is a class that stores a generic piece of data, and then is able to
 * retrieve it, given that the data format is known when retrieving.
 *
 * This is used in the message system to store generic messages, which can then
 * be retrieved, given that the type is already known when retrieval is
 * happening.
 */
class Message {
	/**
	 * The generic stored data
	 */
	std::shared_ptr<StorageBase> store;
public:
	template <typename T>
	Message(std::shared_ptr<T> d);

	/**
	 * This templated function attempts to return the data, in the form of
	 * the template variable
	 * @ return the stored data
	 */
	template <typename T>
	std::shared_ptr<T> Get();
};

class MessageReceiver {
	std::string name; /**< The name of the receiver */
	/**
	 * Whether or not a receiver should be added as a child node, or if it
	 * should be skipped over. This allows for in-between nodes that can be
	 * put in chains but are ignored from a message standpoint.
	 */
	bool makes_level;
	/**
	 * If a receiver should not be added as a child node, this pointer is
	 * set to the message receiver that should be added when AddChild is
	 * called on it.
	 */
	MessageReceiver *real_child;

	/**
	 * A map of children names to children
	 * Needs to be a multimap because several children can have the same
	 * name
	 */
	std::unordered_multimap<std::string, MessageReceiver*> children;
	MessageReceiver *parent; /**< the parent of this object, or NULL */

	/**
	 * Sets the parent of this object
	 * @param p the parent object
	 */
	void SetParent(MessageReceiver *p);

	/**
	 * Finds objects with the path from the iterators, starting from this
	 * object, and stores them in the found set
	 * @param it the current iterator in the path
	 * @param end the end iterator in the path
	 * @param found the set to store found objects in
	 */
	void Find(std::vector<std::string>::const_iterator it,
	          std::vector<std::string>::const_iterator end,
	          std::set<MessageReceiver*> &found);
protected:
	/**
	 * Adds a child object
	 * @param child the child object
	 */
	void AddChild(MessageReceiver *child);

	/**
	 * Removes a child object
	 * @param child the child object
	 */
	void RemoveChild(MessageReceiver *child);

	/**
	 * wraps t in a Message and calls SendMessage(name, id, Message(t))
	 * @param path the path of the objects
	 * @param id the message id
	 * @param t the pointer to store in the message to send
	 * @see SendMessage(std::string, std::string, Message)
	 */
	template <typename T>
	void SendMessage(std::string path, std::string id, std::shared_ptr<T> t);

	/**
	 * Sends a message with an id to objects at the specified path by
	 * storing it in the MessageQueue's queue
	 * @param path the path of the objects
	 * @param id the message id
	 * @param m the message to send
	 */
	void SendMessage(std::string path, std::string id, Message m);

	/**
	 * Checks whether a message receiver should make a level
	 */
	bool MakesLevel() const { return makes_level; }

	/**
	 * If the message receiver shouldn't make a level, this returns a
	 * pointer to the message receiver that should be added as a child
	 * instead. By default, it just returns this message receiver.
	 */
	MessageReceiver *GetRealChild() { return real_child; }
public:
	/**
	 * When passed in a name, the message receiver will act as a normal
	 * receiver, and make_level will be set to true
	 * @param name The name of this message receiver
	 */
	MessageReceiver(std::string name);

	/**
	 * When passed in a pointer to another receiver, the receiver will set
	 * make_level to false and act as a passthrough
	 * @param real_child The passthrough child of this message receiver
	 */
	MessageReceiver(MessageReceiver *real_child);

	virtual ~MessageReceiver();

	/**
	 * Returns the name of the object
	 * @return the object's name
	 */
	const std::string &GetName();

	/**
	 * A virtual function to override for receiving messages. This is
	 * called every time an object receives a message. By default, it
	 * discards all the messages.
	 * @param id the id of the message
	 * @param m the message being received
	 */
	virtual void ReceiveMessage(std::string id, Message m);
};

/**
 * A message queue class, which stores messages to be sent as a queue, and when
 * prompted sends out each message in order
 */
class MessageQueue {
	/**
	 * the queue of messages, ids, and receivers to be sent out
	 */
	std::queue<std::tuple<MessageReceiver*, std::string, Message>> message_queue;

	/**
	 * Private constructor, so only one instance can be created
	 */
	MessageQueue() {}

	/**
	 * Static singleton accessor
	 */
	static MessageQueue &GetInstance();
public:
	/**
	 * Adds a message to the queue of messages
	 * @param to the receiver object of the message
	 * @param id the id of the message
	 * @param m the message itself
	 */
	static void AddMessageToQueue(MessageReceiver *to, std::string id, Message m);

	/**
	 * Flushes the queue of messages, sending them all out in order
	 */
	static void FlushMessageQueue();
};

#include <abxy/messages/Message.inl>

#endif /* MESSAGE_HPP */

