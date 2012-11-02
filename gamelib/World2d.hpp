#ifndef WORLD2D_HPP
#define WORLD2D_HPP

#include <typeinfo>

#include <gamelib/Stage2d.inl>

#include <gamelib/World.inl>
#include <gamelib/Entity2d.inl>

class World2d : public World {
public:
	World2d(Stage2d &parent);
	virtual ~World2d();
};

#endif /* WORLD2D_HPP */

