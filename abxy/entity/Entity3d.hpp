#ifndef ENTITY3D_HPP
#define ENTITY3D_HPP

#include <abxy/entity/Entity.hpp>

#include <abxy/math/Vector3.hpp>

class Entity3d : public Entity {
	Vector3 position;
public:
	Entity3d();
	Entity3d(const Vector3 &position);

	virtual void OnLoad(LoadData &data) override { (void)data; }
	virtual void OnUnload() override {}

	Vector3 &Position() { return position; }
	const Vector3 &Position() const { return position; }

	virtual void Update() override {}

	virtual Matrix4 GetTransform() const;
};

#endif /* ENTITY3D_HPP */

