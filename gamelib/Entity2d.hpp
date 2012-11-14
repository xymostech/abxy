#ifndef ENTITY2D_HPP
#define ENTITY2D_HPP

#include <gamelib/Vector.inl>

class Entity2d : public Entity {
	Vector2 position;
	Vector2 velocity;
	float angle;
	float angvelocity;
public:
	Entity2d();
	Entity2d(long type,
	         const Vector2& position,
	         const Vector2& velocity,
	         float angle,
	         float angvelocity);

	virtual ~Entity2d();

	virtual const Vector2 &Position() const;
	virtual const Vector2 &Velocity() const;
	virtual const float &Angle() const;
	virtual const float &AngVelocity() const;

	virtual Entity2d &SetPosition(const Vector2 &new_position);
	virtual Entity2d &Shift(const Vector2 &offset);
	virtual Entity2d &SetVelocity(const Vector2 &new_velocity);

	virtual Entity2d &SetAngle(const float &new_angle);
	virtual Entity2d &turn(const float &tilt);
	virtual Entity2d &SetAngVelocity(const float &new_angvelocity);

	virtual void Update();
	virtual void Draw(Matrix4 model_matrix) const;
};

#endif /* ENTITY2D_HPP */

