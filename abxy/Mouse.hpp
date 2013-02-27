#ifndef MOUSE_HPP
#define MOUSE_HPP

#include <abxy/math/Vector2.hpp>

namespace Mouse {
	Vector2 Position();

	bool IsLeftPressed();
	bool IsRightPressed();
}

#endif /* MOUSE_HPP */

