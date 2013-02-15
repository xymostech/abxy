#include <abxy/ProjectionOrtho2d.hpp>

ProjectionOrtho2d::ProjectionOrtho2d()
: camera_clip_matrix(1.0)
, world_camera_matrix(1.0)
{
	SetCameraToClipMatrix(camera_clip_matrix);
	SetWorldToCameraMatrix(world_camera_matrix);
}

void ProjectionOrtho2d::Resize() {
	glViewport(0, 0, window_width, window_height);
	camera_clip_matrix[0][0] = 2.0 / (float) window_width * 10;
	camera_clip_matrix[1][1] = 2.0 / (float) window_height * 10;
	SetCameraToClipMatrix(camera_clip_matrix);
}

