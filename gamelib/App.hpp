#ifndef APP_HPP
#define APP_HPP

#include <gamelib/GL/GL.hpp>

class App {
public:
	App() {

	}

	virtual ~App() {
		Shutdown();
	}

	virtual void Startup() {
		glfwInit();

		glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
		glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 2);
		glfwOpenWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		glfwOpenWindow(800, 600, 8, 8, 8, 8, 16, 0, GLFW_WINDOW);
	}

	virtual void Shutdown() {
		glfwCloseWindow();
		glfwTerminate();
	}

	virtual bool IsOpen() {
		return glfwGetWindowParam(GLFW_OPENED);
	}

	virtual void Update() {

	}

	virtual void Draw() {

	}
};

#endif /* APP_HPP */

