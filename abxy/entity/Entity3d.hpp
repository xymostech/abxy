#ifndef ENTITY3D_HPP
#define ENTITY3D_HPP

#include <abxy/entity/Entity.hpp>

#include <abxy/math/Vector3.hpp>

class Entity3d : public Entity {
	Vector3 position;
public:
	Entity3d(const std::string &name);
	Entity3d(const std::string &name, const Vector3 &position);

	Vector3 &Position() { return position; }
	const Vector3 &Position() const { return position; }

	Matrix4 GetTransform() const;
};

#endif /* ENTITY3D_HPP */

