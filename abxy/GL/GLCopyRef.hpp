#ifndef GLCOPYREF_HPP
#define GLCOPYREF_HPP

template <typename RefType>
class GLCopyRef {
	RefType ref;
	bool created;
public:
	GLCopyRef() : ref(), created(false) {}

	GLCopyRef(RefType ref) : ref(ref), created(true) {}

	GLCopyRef(const GLCopyRef<RefType> &copy)
	: ref(copy.ref)
	, created(copy.created) {}

	GLCopyRef(GLCopyRef<RefType> &&move)
	: ref(move.ref)
	, created(move.created)
	{
		move.ref = RefType();
		move.created = false;
	}

	GLCopyRef<RefType> &operator=(const GLCopyRef<RefType> &copy) {
		ref = copy.ref;
		created = copy.created;

		return *this;
	}

	GLCopyRef<RefType> &operator=(GLCopyRef<RefType> &&move) {
		ref = move.ref;
		created = move.created;

		move.ref = RefType();
		move.created = false;

		return *this;
	}

	RefType GetRef() const { return ref; }
	bool IsCreated() const { return created; }
};

#endif /* GLCOPYREF_HPP */

