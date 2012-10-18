#ifndef PERSPECTIVE2D_HPP
#define PERSPECTIVE2D_HPP

#include <gamelib/Perspective.hpp>
#include <gamelib/GL/GL.hpp>

#include <iostream>

class Perspective2d : public Perspective {
	Matrix4 camera_clip_matrix, world_camera_matrix;
public:
	Perspective2d()
	: camera_clip_matrix(1.0)
	, world_camera_matrix(1.0)
	{
		SetCameraToClipMatrix(camera_clip_matrix);
		SetWorldToCameraMatrix(world_camera_matrix);
	}

	virtual void Resize() {
		glViewport(0, 0, window_width, window_height);
		camera_clip_matrix[0][0] = 2.0 / (float) window_width * 10;
		camera_clip_matrix[1][1] = 2.0 / (float) window_height * 10;
		SetCameraToClipMatrix(camera_clip_matrix);
	}

	void Setup() const {
	}
};

#endif /* PERSPECTIVE2D_HPP */

