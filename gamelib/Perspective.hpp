#ifndef PERSPECTIVE_HPP
#define PERSPECTIVE_HPP

#include <vector>
#include <iostream>

#include <gamelib/GL/GL.hpp>
#include <gamelib/GL/GLBufferRef.inl>
#include <gamelib/Matrix.inl>

class Perspective {
	static std::vector<Perspective*> active_perspectives;

	GLBufferRef<GL_UNIFORM_BUFFER> uniform_buffer;

	GLuint uniform_matrices_binding_index;
public:
	static int window_width, window_height;

	Perspective();

	virtual void SetCameraToClipMatrix(Matrix4 &mat);
	virtual void SetWorldToCameraMatrix(Matrix4 &mat);

	static void GLFWCALL ResizeCallback(int width, int height);

	void SetActivePerspective();
	void RemovePerspective();

	GLuint GetUniformBindingIndex();

	virtual void Resize() = 0;
};

#endif /* PERSPECTIVE_HPP */

