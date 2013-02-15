#include <abxy/Key.hpp>

namespace Key {
	bool IsKeyPressed(int key) {
		return glfwGetKey(key) == GLFW_PRESS;
	}
}

