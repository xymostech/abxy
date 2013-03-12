#include <abxy/projection/ProjectionFrustum.hpp>

#include <cmath>

ProjectionFrustum::ProjectionFrustum(float fov, float z_near, float z_far)
: camera_clip_matrix(1.0)
, world_camera_matrix(1.0)
, fov(fov)
, z_near(z_near)
, z_far(z_far)
{
	SetupCameraClip();

	SetCameraToClipMatrix(camera_clip_matrix);
	SetWorldToCameraMatrix(world_camera_matrix);
}

void ProjectionFrustum::SetupCameraClip() {
	frustum_scale = GetFrustumScale(fov);

	camera_clip_matrix[0].x() = frustum_scale;
	camera_clip_matrix[1].y() = frustum_scale;
	camera_clip_matrix[2].z() = (z_far + z_near) / (z_near - z_far);
	camera_clip_matrix[2].w() = -1.0;
	camera_clip_matrix[3].z() = (2 * z_far * z_near) / (z_near - z_far);
}

float ProjectionFrustum::GetFrustumScale(float fov) {
	const float deg_to_rad = M_PI / 180.0;
	float fov_rad = fov * deg_to_rad;
	return 1.0 / std::tan(fov_rad / 2.0);
}

void ProjectionFrustum::Resize() {
	glViewport(0, 0, window_width, window_height);
}
