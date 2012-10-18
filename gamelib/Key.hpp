#ifndef KEY_HPP
#define KEY_HPP

#include <gamelib/GL/GL.hpp>

namespace Key {
	bool IsKeyPressed(char key) {
		return glfwGetKey(key) == GLFW_PRESS;
	}
}

#endif /* KEY_HPP */

