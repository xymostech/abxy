#include "Entity3d.hpp"

Entity3d::Entity3d(const std::string &name)
: MessageReceiver(name)
, position()
{
}

Entity3d::Entity3d(const std::string &name, const Vector3 &position)
: MessageReceiver(name)
, position(position)
{
}

Matrix4 Entity3d::GetTransform() const {
	return Matrix4().Translate(Position());
}
