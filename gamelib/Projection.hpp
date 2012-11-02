#ifndef PROJECTION_HPP
#define PROJECTION_HPP

#include <vector>
#include <iostream>

#include <gamelib/GL/GL.hpp>
#include <gamelib/GL/GLBufferRef.inl>
#include <gamelib/Matrix.inl>

class Projection {
	static std::vector<Projection*> active_projections;

	GLBufferRef<GL_UNIFORM_BUFFER> uniform_buffer;
	GLuint uniform_matrices_binding_index;

	void SetActiveProjection();
	void UnsetActiveProjection();
public:
	Projection();
	virtual ~Projection();

	virtual void SetCameraToClipMatrix(Matrix4 &mat);
	virtual void SetWorldToCameraMatrix(Matrix4 &mat);
	GLuint GetUniformBindingIndex();

	virtual void Resize() = 0;

	static int window_width, window_height;
	static void GLFWCALL ResizeCallback(int width, int height);
};

#endif /* PROJECTION_HPP */

