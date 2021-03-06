#include <abxy/App.hpp>
#include <abxy/util/Path.hpp>
#include <abxy/util/Logger.hpp>

#include <iostream>

#include <ao/ao.h>

#ifdef __APPLE__
#define MIN_GL_MAJOR 3
#define MIN_GL_MINOR 2
#else
#define MIN_GL_MAJOR 3
#define MIN_GL_MINOR 1
#endif

App::App() {
	glfwInit();

	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, MIN_GL_MAJOR);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, MIN_GL_MINOR);
	glfwOpenWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glfwOpenWindow(1, 1, 8, 8, 8, 8, 16, 0, GLFW_WINDOW);

#ifndef __APPLE__
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		printf("Error loading GLEW: %s\n", glewGetErrorString(err));
	}
#endif

	glfwCloseWindow();
}

App::~App() {
	Shutdown();
}

void App::Startup() {
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, MIN_GL_MAJOR);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, MIN_GL_MINOR);
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

	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LEQUAL);
	glDepthRange(0.0, 1.0);

	ao_initialize();

	Util::SetCWD(Util::GetExecutablePath());

	std::string logger_path = Util::Logger::Setup("/tmp/logger.log");
	Util::Logger::Debug("Started logging");
	std::cout << "Logging to: " << logger_path << std::endl;
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

void App::Draw() const {

}

