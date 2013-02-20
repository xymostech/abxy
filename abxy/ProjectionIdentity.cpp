#include <abxy/ProjectionIdentity.hpp>

ProjectionIdentity::ProjectionIdentity()
: camera_clip_matrix(1.0)
, world_camera_matrix(1.0)
{
	SetCameraToClipMatrix(camera_clip_matrix);
	SetWorldToCameraMatrix(world_camera_matrix);
}

void ProjectionIdentity::Resize() {
	glViewport(0, 0, window_width, window_height);
}
