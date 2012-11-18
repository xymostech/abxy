#ifndef GAME_HPP
#define GAME_HPP

#include <stdexcept>
#include <iostream>

#include <gamelib/App.inl>
#include <gamelib/Stage.hpp>

#include <gamelib/messages/Message.inl>

class Game : public App, virtual public MessageReceiver {
	float sleep_time;
	Stage *current_stage;
public:
	Game(float fps);
	virtual ~Game() = 0;

	virtual void Update();
	virtual void Draw();

	virtual void SetStage(Stage *new_stage);
	virtual Stage *GetStage();
};

#endif /* GAME_HPP */

