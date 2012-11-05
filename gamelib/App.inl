#ifndef APP_INL
#define APP_INL

#include <gamelib/App.hpp>

App::~App() {
	Shutdown();
}

void App::Startup() {
	glfwInit();

	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 2);
	glfwOpenWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glfwOpenWindow(800, 600, 8, 8, 8, 8, 16, 0, GLFW_WINDOW);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void App::Shutdown() {
	glfwCloseWindow();
	glfwTerminate();
}

bool App::IsOpen() {
	return glfwGetWindowParam(GLFW_OPENED);
}

void App::Update() {

}

void App::Draw() {

}

#endif /* APP_INL */

