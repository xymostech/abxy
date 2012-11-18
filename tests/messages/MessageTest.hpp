#ifndef MESSAGETEST_HPP
#define MESSAGETEST_HPP

#include <gamelib/messages/Message.inl>

SUITE(MessageSuite) {

	struct Child : public MessageReceiver {
		int *received;

		Child(std::string name, int *received)
		: MessageReceiver(name)
		, received(received)
		{}

		virtual void ReceiveMessage(std::string id, Message m) {
			++*received;
		}

		void Send(std::string name) {
			SendMessage(name, "", std::make_shared<int>());
		}
	};

	struct Parent : public MessageReceiver {
		int *received;

		Parent(std::string name, int *received)
		: MessageReceiver(name)
		, received(received)
		{}

		virtual void ReceiveMessage(std::string id, Message m) {
			++*received;
		}

		void AddChild(Child *c) {
			MessageReceiver::AddChild(c);
		}

		void Send(std::string name) {
			SendMessage(name, "", std::make_shared<int>());
		}
	};

	struct Grandparent : public MessageReceiver {
		int *received;

		Grandparent(std::string name, int *received)
		: MessageReceiver(name)
		, received(received)
		{}

		virtual void ReceiveMessage(std::string id, Message m) {
			++*received;
		}

		void AddChild(Parent *p) {
			MessageReceiver::AddChild(p);
		}

		void Send(std::string name) {
			SendMessage(name, "", std::make_shared<int>());
		}
	};

	struct MessageFixture {
		MessageFixture()
		: gpr(0)
		, p1r(0)
		, p2r(0)
		, c11r(0)
		, c12r(0)
		, c13r(0)
		, c21r(0)
		, c22r(0)
		, c23r(0)
		, gp("gp", &gpr)
		, p1("p1", &p1r)
		, p2("p2", &p2r)
		, c11("c1", &c11r)
		, c12("c1", &c12r)
		, c13("c2", &c13r)
		, c21("c1", &c21r)
		, c22("c2", &c22r)
		, c23("c2", &c23r)
		{
			gp.AddChild(&p1);
			gp.AddChild(&p2);

			p1.AddChild(&c11);
			p1.AddChild(&c12);
			p1.AddChild(&c13);

			p2.AddChild(&c21);
			p2.AddChild(&c22);
			p2.AddChild(&c23);
		}

		~MessageFixture() {
			MessageRouter::FlushMessages();
		}

		int gpr, p1r, p2r, c11r, c12r, c13r, c21r, c22r, c23r;

		Grandparent gp;
		Parent p1, p2;
		Child c11, c12, c13, c21, c22, c23;
	};

	TEST_FIXTURE(MessageFixture, FindChild) {
		CHECK_EQUAL(0, p1r);

		gp.Send("p1");
		MessageRouter::FlushMessages();

		CHECK_EQUAL(1, p1r);
	}

	TEST_FIXTURE(MessageFixture, FindGrandChild) {
		CHECK_EQUAL(0, c13r);

		gp.Send("p1/c2");
		MessageRouter::FlushMessages();

		CHECK_EQUAL(1, c13r);
	}

	TEST_FIXTURE(MessageFixture, FindMultipleChildren) {
		CHECK_EQUAL(0, c11r);
		CHECK_EQUAL(0, c12r);

		p1.Send("c1");
		MessageRouter::FlushMessages();

		CHECK_EQUAL(1, c11r);
		CHECK_EQUAL(1, c12r);
	}

	TEST_FIXTURE(MessageFixture, FindMultipleGrandChildren) {
		CHECK_EQUAL(0, c11r);
		CHECK_EQUAL(0, c12r);

		gp.Send("p1/c1");
		MessageRouter::FlushMessages();

		CHECK_EQUAL(1, c11r);
		CHECK_EQUAL(1, c12r);
	}

	TEST_FIXTURE(MessageFixture, FindParent) {
		CHECK_EQUAL(0, gpr);

		p1.Send("..");
		MessageRouter::FlushMessages();

		CHECK_EQUAL(1, gpr);
	}

	TEST_FIXTURE(MessageFixture, FindGrandParent) {
		CHECK_EQUAL(0, gpr);

		c11.Send("../..");
		MessageRouter::FlushMessages();

		CHECK_EQUAL(1, gpr);
	}

	TEST_FIXTURE(MessageFixture, FindSelf) {
		CHECK_EQUAL(0, p1r);
		CHECK_EQUAL(0, p2r);

		p1.Send("../p1");
		p2.Send("c1/..");
		MessageRouter::FlushMessages();

		CHECK_EQUAL(1, p1r);
		CHECK_EQUAL(1, p2r);
	}

	TEST_FIXTURE(MessageFixture, FindSelf) {
		CHECK_EQUAL(0, p1r);
		CHECK_EQUAL(0, p2r);

		p1.Send("../p1");
		p2.Send("c1/..");
		MessageRouter::FlushMessages();

		CHECK_EQUAL(1, p1r);
		CHECK_EQUAL(1, p2r);
	}

	TEST_FIXTURE(MessageFixture, FindSelf) {
		CHECK_EQUAL(0, p1r);
		CHECK_EQUAL(0, p2r);

		p1.Send("../p1");
		p2.Send("c1/..");
		MessageRouter::FlushMessages();

		CHECK_EQUAL(1, p1r);
		CHECK_EQUAL(1, p2r);
	}
}

#endif /* MESSAGETEST_HPP */

