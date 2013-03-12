#ifndef PROJECTIONIDENTITY_HPP
#define PROJECTIONIDENTITY_HPP

#include <abxy/projection/Projection.hpp>

class ProjectionIdentity : public Projection {
	Matrix4 camera_clip_matrix, world_camera_matrix;
public:
	ProjectionIdentity();

	virtual void Resize();
};

#endif /* PROJECTIONIDENTITY_HPP */

