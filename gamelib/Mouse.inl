#ifndef MOUSE_INL
#define MOUSE_INL

#include <gamelib/Mouse.hpp>

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

#endif /* MOUSE_INL */

