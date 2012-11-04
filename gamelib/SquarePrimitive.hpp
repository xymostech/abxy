#ifndef SQUAREPRIMITIVE_HPP
#define SQUAREPRIMITIVE_HPP

#include <gamelib/Primitive.inl>

class SquarePrimitive : public virtual Primitive {
public:
	SquarePrimitive(std::string program_name);
	virtual ~SquarePrimitive();
};

#endif /* SQUAREPRIMITIVE_HPP */

