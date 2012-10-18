#ifndef MOUSE_HPP
#define MOUSE_HPP

#include <gamelib/GL/GL.hpp>
#include <gamelib/Vector.hpp>

namespace Mouse {
	Vector2 Position() {
		int x, y;
		glfwGetMousePos(&x, &y);
		return Vector2(x, y);
	}

	bool IsLeftPressed() {
		return glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
	}

	bool IsRightPressed() {
		return glfwGetMouseButton(GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS;
	}
}

#endif /* MOUSE_HPP */

