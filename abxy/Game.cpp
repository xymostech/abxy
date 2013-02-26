#include <abxy/Game.hpp>

Game::Game(float fps)
, App()
, sleep_time(1 / fps)
{
	
}

void Game::Update() {
	base.Update();

	MessageQueue::FlushMessageQueue();
	glfwSleep(sleep_time);
}

void Game::Draw() const {
	base.Draw();

	glfwSwapBuffers();
}
