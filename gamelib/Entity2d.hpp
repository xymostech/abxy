#ifndef ENTITY2D_HPP
#define ENTITY2D_HPP

#include <gamelib/Vector.hpp>

class Entity2d : public Entity {
	Vector2 position;
	Vector2 velocity;
	float angle;
	float angvelocity;
public:
	Entity2d(const Vector2& position = Vector2(),
	         const Vector2& velocity = Vector2(),
	         const float &angle = 0,
	         const float &angvelocity = 0)
	: position(position)
	, velocity(velocity)
	, angle(angle)
	, angvelocity(angvelocity)
	{
		
	}

	virtual ~Entity2d() {
		
	}

	virtual const Vector2 &Position() const {
		return position;
	}

	virtual const Vector2 &Velocity() const {
		return velocity;
	}

	virtual const float &Angle() const {
		return angle;
	}

	virtual const float &AngVelocity() const {
		return angvelocity;
	}

	virtual Entity2d &SetPosition(const Vector2 &new_position) {
		position = new_position;
		return *this;
	}

	virtual Entity2d &Shift(const Vector2 &offset) {
		position += offset;
		return *this;
	}

	virtual Entity2d &SetVelocity(const Vector2 &new_velocity) {
		velocity = new_velocity;
		return *this;
	}

	virtual Entity2d &SetAngle(const float &new_angle) {
		angle = new_angle;
		return *this;
	}

	virtual Entity2d &turn(const float &tilt) {
		angle += tilt;
		return *this;
	}

	virtual Entity2d &SetAngVelocity(const float &new_angvelocity) {
		angvelocity = new_angvelocity;
		return *this;
	}

	virtual void Update() {
		position += velocity;
		angle += angvelocity;
	}

	virtual void Draw(Matrix4 model_matrix) const {
		
	}
};

#endif /* ENTITY2D_HPP */

