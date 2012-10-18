#ifndef WORLD2D_HPP
#define WORLD2D_HPP

#include <typeinfo>

#include <gamelib/Stage2d.hpp>

#include <gamelib/World.hpp>
#include <gamelib/Entity2d.hpp>

class World2d : public World {
public:
	World2d(Stage &parent)
	: World(parent)
	{
		
	}

	virtual ~World2d() {
		
	}
};

#endif /* WORLD2D_HPP */

