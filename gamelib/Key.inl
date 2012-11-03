#ifndef KEY_INL
#define KEY_INL

#include <gamelib/Key.hpp>

namespace Key {
	bool IsKeyPressed(int key) {
		return glfwGetKey(key) == GLFW_PRESS;
	}
}

#endif /* KEY_INL */

