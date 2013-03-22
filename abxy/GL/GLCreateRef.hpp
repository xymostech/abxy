#ifndef GLCREATEREF_HPP
#define GLCREATEREF_HPP

template <typename RefType>
class GLCreateRef {
	RefType ref;
	bool created;
protected:
	void SetRef(RefType new_ref) {
		if (!created) {
			ref = new_ref;
			created = true;
		}
	}

	const RefType &GetRef() { return ref; }
public:
	GLCreateRef() : ref(), created(false) {}

	GLCreateRef(const GLCreateRef<RefType> &copy) = delete;

	GLCreateRef(GLCreateRef<RefType> &&move)
	: ref(move.ref)
	, created(move.created)
	{
		move.ref = RefType();
		move.created = false;
	}

	GLCreateRef<RefType> &operator=(const GLCreateRef<RefType> &copy) = delete;

	GLCreateRef<RefType> &operator=(GLCreateRef<RefType> &&move) {
		ref = move.ref;
		created = move.created;

		move.ref = RefType();
		move.created = false;

		return *this;
	}

	RefType GetRef() const { return ref; }
	bool IsCreated() const { return created; }
};

#endif /* GLCREATEREF_HPP */

