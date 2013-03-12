#ifndef PROJECTIONFRUSTUM_HPP
#define PROJECTIONFRUSTUM_HPP

#include <abxy/projection/Projection.hpp>

class ProjectionFrustum : public Projection {
	Matrix4 camera_clip_matrix, world_camera_matrix;

	float fov;
	float z_near, z_far;
	float frustum_scale;

	void SetupCameraClip();
	float GetFrustumScale(float fov);
public:
	ProjectionFrustum(
		float fov = 45.0, float z_near = 0.01, float z_far = 1000.0
	);

	virtual void Resize();
};

#endif /* PROJECTIONFRUSTUM_HPP */

