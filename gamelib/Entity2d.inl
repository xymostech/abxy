#ifndef ENTITY2D_INL
#define ENTITY2D_INL

#include <gamelib/Entity2d.hpp>

Entity2d::Entity2d(const Vector2& position,
                   const Vector2& velocity,
                   float angle,
                   float angvelocity)
: Entity2d(0, position, velocity, angle, angvelocity)
{
	
}

Entity2d::Entity2d(long type,
                   const Vector2& position,
                   const Vector2& velocity,
                   float angle,
                   float angvelocity)
: MessageReceiver("entity")
, Entity(type)
, position(position)
, velocity(velocity)
, angle(angle)
, angvelocity(angvelocity)
{
	
}

Entity2d::~Entity2d() {
	
}

const Vector2 &Entity2d::Position() const {
	return position;
}

const Vector2 &Entity2d::Velocity() const {
	return velocity;
}

const float &Entity2d::Angle() const {
	return angle;
}

const float &Entity2d::AngVelocity() const {
	return angvelocity;
}

Entity2d &Entity2d::SetPosition(const Vector2 &new_position) {
	position = new_position;
	return *this;
}

Entity2d &Entity2d::Shift(const Vector2 &offset) {
	position += offset;
	return *this;
}

Entity2d &Entity2d::SetVelocity(const Vector2 &new_velocity) {
	velocity = new_velocity;
	return *this;
}

Entity2d &Entity2d::SetAngle(const float &new_angle) {
	angle = new_angle;
	return *this;
}

Entity2d &Entity2d::turn(const float &tilt) {
	angle += tilt;
	return *this;
}

Entity2d &Entity2d::SetAngVelocity(const float &new_angvelocity) {
	angvelocity = new_angvelocity;
	return *this;
}

void Entity2d::Transform(Matrix4 &model_matrix) const {
	model_matrix.Rotate(Vector3(0, 0, 1), Angle());
	model_matrix.Translate(Vector3(Position().x, Position().y, 0));
}

void Entity2d::Update() {
	position += velocity;
	angle += angvelocity;
}

void Entity2d::Draw(Matrix4 model_matrix) const {
	
}

#endif /* ENTITY2D_INL */

