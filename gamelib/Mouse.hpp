#ifndef MOUSE_HPP
#define MOUSE_HPP

#include <gamelib/GL/GL.hpp>
#include <gamelib/Vector.inl>

namespace Mouse {
	Vector2 Position();

	bool IsLeftPressed();
	bool IsRightPressed();
}

#endif /* MOUSE_HPP */

