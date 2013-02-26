#ifndef GAME_HPP
#define GAME_HPP

#include <stdexcept>
#include <iostream>

#include <abxy/App.hpp>
#include <abxy/entity/BaseEntity.hpp>

class Game : public App {
	float sleep_time;
	BaseEntity base;
public:
	Game(float fps);

	virtual void Update();
	virtual void Draw() const;

	BaseEntity *GetBase() { return &base; }
};

#endif /* GAME_HPP */

