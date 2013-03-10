#include "Entity3d.hpp"

Entity3d::Entity3d()
: MessageReceiver("entity3d")
, position()
{
}

Entity3d::Entity3d(const Vector3 &position)
: MessageReceiver("entity3d")
, position(position)
{
}

Matrix4 Entity3d::GetTransform() const {
	return Matrix4().Translate(Position());
}
