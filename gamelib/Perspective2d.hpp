#ifndef PERSPECTIVE2D_HPP
#define PERSPECTIVE2D_HPP

#include <gamelib/Perspective.inl>
#include <gamelib/GL/GL.hpp>

#include <iostream>

class Perspective2d : public Perspective {
	Matrix4 camera_clip_matrix, world_camera_matrix;
public:
	Perspective2d();

	virtual void Resize();

	void Setup() const;
};

#endif /* PERSPECTIVE2D_HPP */

