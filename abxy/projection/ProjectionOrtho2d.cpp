#include <abxy/projection/ProjectionOrtho2d.hpp>

ProjectionOrtho2d::ProjectionOrtho2d()
: camera_clip_matrix(1.0)
, world_camera_matrix(1.0)
{
	SetCameraToClipMatrix(camera_clip_matrix);
	SetWorldToCameraMatrix(world_camera_matrix);

	Resize();
}

void ProjectionOrtho2d::Resize() {
	glViewport(0, 0, window_width, window_height);

	float max = std::max(window_width, window_height);
	camera_clip_matrix[0][0] = max / (float) window_width;
	camera_clip_matrix[1][1] = max / (float) window_height;
	SetCameraToClipMatrix(camera_clip_matrix);
}

