#ifndef PERSPECTIVE_HPP
#define PERSPECTIVE_HPP

#include <vector>
#include <iostream>

#include <gamelib/GL/GL.hpp>
#include <gamelib/GL/GLBufferRef.hpp>
#include <gamelib/Matrix.hpp>

class Perspective {
	static std::vector<Perspective*> active_perspectives;

	GLBufferRef<GL_UNIFORM_BUFFER> uniform_buffer;

	GLuint uniform_matrices_binding_index;
public:
	static int window_width, window_height;

	Perspective()
	: uniform_matrices_binding_index(1)
	{
		glfwSetWindowSizeCallback(ResizeCallback);

		uniform_buffer.Bind();
		uniform_buffer.SetData(
			sizeof(Matrix4) * 2, NULL, GL_STREAM_DRAW
		);
		uniform_buffer.Unbind();

		uniform_buffer.BindRange(
			uniform_matrices_binding_index, 0, sizeof(Matrix4) * 2
		);
	}

	virtual void SetCameraToClipMatrix(Matrix4 &mat) {
		uniform_buffer.Bind();
		uniform_buffer.SetSubData(
			0, sizeof(Matrix4), mat.GetData()
		);
		uniform_buffer.Unbind();
	}

	virtual void SetWorldToCameraMatrix(Matrix4 &mat) {
		uniform_buffer.Bind();
		uniform_buffer.SetSubData(
			sizeof(Matrix4), sizeof(Matrix4), mat.GetData()
		);
		uniform_buffer.Unbind();
	}

	static void GLFWCALL ResizeCallback(int width, int height) {
		window_width = width;
		window_height = height;
		std::vector<Perspective*>::iterator it,
			end = active_perspectives.end();
		for (it = active_perspectives.begin(); it != end; ++it) {
			(*it)->Resize();
		}
	}

	virtual void SetActivePerspective() {
		active_perspectives.push_back(this);
		this->Resize();
	}

	virtual void RemovePerspective() {
		std::vector<Perspective*>::iterator it,
			end = active_perspectives.end();
		for (it = active_perspectives.begin(); it != end; ++it) {
			if (this == *it) {
				active_perspectives.erase(it);
				return;
			}
		}
	}

	virtual GLuint GetUniformBindingIndex() {
		return uniform_matrices_binding_index;
	}

	virtual void Resize() = 0;
};

std::vector<Perspective*> Perspective::active_perspectives =
	std::vector<Perspective*>();
int Perspective::window_height = 0;
int Perspective::window_width = 0;

#endif /* PERSPECTIVE_HPP */

