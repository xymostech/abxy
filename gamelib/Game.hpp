#ifndef GAME_HPP
#define GAME_HPP

#include <stdexcept>
#include <iostream>

#include <gamelib/App.hpp>
#include <gamelib/Stage.hpp>

class Game : public App {
	float sleep_time;
	Stage *current_stage;
public:
	Game(float fps = 120)
	: App()
	, sleep_time(1 / fps)
	, current_stage(NULL)
	{
		
	}

	virtual ~Game() {
		
	}

	virtual void Update() {
		if (current_stage) {
			current_stage->Update();
		}
		glfwSleep(sleep_time);
	}

	virtual void Draw() {
		if (current_stage) {
			current_stage->Draw();
		}

		glfwSwapBuffers();
	}

	virtual void SetStage(Stage *new_stage) {
		try {
			if (current_stage) {
				current_stage->Unload();
			}
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		current_stage = new_stage;

		try {
			new_stage->Load();
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			exit(1);
		}
	}
};

#endif /* GAME_HPP */

