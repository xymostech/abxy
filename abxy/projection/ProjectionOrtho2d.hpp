#ifndef PROJECTIONORTHO2D_HPP
#define PROJECTIONORTHO2D_HPP

#include <abxy/projection/Projection.hpp>
#include <abxy/GL/GL.hpp>

class ProjectionOrtho2d : public Projection {
	Matrix4 camera_clip_matrix, world_camera_matrix;
public:
	ProjectionOrtho2d();

	virtual void Resize();
};

#endif /* PROJECTIONORTHO2D_HPP */

