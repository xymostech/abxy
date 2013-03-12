#include <abxy/Game.hpp>

Game::Game(float fps)
: App()
, sleep_time(1 / fps)
{
	
}

void Game::Update() {
	base.Update();

	MessageQueue::FlushMessageQueue();
	glfwSleep(sleep_time);
}

void Game::Draw() const {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	base.Draw();

	glfwSwapBuffers();
}
