#include <abxy/App.hpp>
#include <ao/ao.h>

App::~App() {
	Shutdown();
}

void App::Startup() {
	glfwInit();

	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 1);
	glfwOpenWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glfwOpenWindow(800, 600, 8, 8, 8, 8, 16, 0, GLFW_WINDOW);

#ifndef __APPLE__
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		printf("Error loading GLEW: %s\n", glewGetErrorString(err));
	}
#endif

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	ao_initialize();
}

void App::Shutdown() {
	glfwCloseWindow();
	glfwTerminate();

	ao_shutdown();
}

bool App::IsOpen() {
	return glfwGetWindowParam(GLFW_OPENED);
}

void App::Update() {

}

void App::Draw() {

}

