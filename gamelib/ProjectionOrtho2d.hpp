#ifndef PROJECTIONORTHO2D_HPP
#define PROJECTIONORTHO2D_HPP

#include <gamelib/Projection.inl>
#include <gamelib/GL/GL.hpp>

#include <iostream>

class ProjectionOrtho2d : public Projection {
	Matrix4 camera_clip_matrix, world_camera_matrix;
public:
	ProjectionOrtho2d();

	virtual void Resize();
};

#endif /* PROJECTIONORTHO2D_HPP */

