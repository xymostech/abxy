#ifndef PERSPECTIVE_INL
#define PERSPECTIVE_INL

#include <gamelib/Perspective.hpp>

Perspective::Perspective()
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

void Perspective::SetCameraToClipMatrix(Matrix4 &mat) {
	uniform_buffer.Bind();
	uniform_buffer.SetSubData(
		0, sizeof(Matrix4), mat.GetData()
	);
	uniform_buffer.Unbind();
}

void Perspective::SetWorldToCameraMatrix(Matrix4 &mat) {
	uniform_buffer.Bind();
	uniform_buffer.SetSubData(
		sizeof(Matrix4), sizeof(Matrix4), mat.GetData()
	);
	uniform_buffer.Unbind();
}

void GLFWCALL Perspective::ResizeCallback(int width, int height) {
	window_width = width;
	window_height = height;
	std::vector<Perspective*>::iterator it,
		end = active_perspectives.end();
	for (it = active_perspectives.begin(); it != end; ++it) {
		(*it)->Resize();
	}
}

void Perspective::SetActivePerspective() {
	active_perspectives.push_back(this);
	this->Resize();
}

void Perspective::RemovePerspective() {
	std::vector<Perspective*>::iterator it,
		end = active_perspectives.end();
	for (it = active_perspectives.begin(); it != end; ++it) {
		if (this == *it) {
			active_perspectives.erase(it);
			return;
		}
	}
}

GLuint Perspective::GetUniformBindingIndex() {
	return uniform_matrices_binding_index;
}

std::vector<Perspective*> Perspective::active_perspectives =
	std::vector<Perspective*>();

int Perspective::window_height = 0;
int Perspective::window_width = 0;

#endif /* PERSPECTIVE_INL */

