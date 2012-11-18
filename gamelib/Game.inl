#ifndef GAME_INL
#define GAME_INL

#include <gamelib/Game.hpp>

Game::Game(float fps)
: MessageReceiver("game")
, App()
, sleep_time(1 / fps)
, current_stage(NULL)
{
	
}

Game::~Game() {
	
}

void Game::Update() {
	if (current_stage) {
		current_stage->Update();
	}

	MessageQueue::FlushMessageQueue();
	glfwSleep(sleep_time);
}

void Game::Draw() {
	if (current_stage) {
		current_stage->Draw();
	}

	glfwSwapBuffers();
}

void Game::SetStage(Stage *new_stage) {
	try {
		if (current_stage) {
			current_stage->Unload();
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	current_stage = new_stage;

	MessageReceiver::AddChild(new_stage);

	try {
		new_stage->Load(this);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		exit(1);
	}
}

Stage *Game::GetStage() {
	return current_stage;
}


#endif /* GAME_INL */
