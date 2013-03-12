#include <abxy/projection/Projection.hpp>

void Projection::SetActiveProjection() {
	active_projections.push_back(this);
}

void Projection::UnsetActiveProjection() {
	std::vector<Projection*>::iterator it,
		end = active_projections.end();
	for (it = active_projections.begin(); it != end; ++it) {
		if (this == *it) {
			active_projections.erase(it);
			return;
		}
	}
}

Projection::Projection()
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

	SetActiveProjection();
}

Projection::~Projection() {
	UnsetActiveProjection();
}

void Projection::SetCameraToClipMatrix(Matrix4 &mat) {
	uniform_buffer.Bind();
	uniform_buffer.SetSubData(
		0, sizeof(Matrix4), mat.GetData()
	);
	uniform_buffer.Unbind();
}

void Projection::SetWorldToCameraMatrix(Matrix4 &mat) {
	uniform_buffer.Bind();
	uniform_buffer.SetSubData(
		sizeof(Matrix4), sizeof(Matrix4), mat.GetData()
	);
	uniform_buffer.Unbind();
}

GLuint Projection::GetUniformBindingIndex() {
	return uniform_matrices_binding_index;
}

void GLFWCALL Projection::ResizeCallback(int width, int height) {
	window_width = width;
	window_height = height;
	std::vector<Projection*>::iterator it,
		end = active_projections.end();
	for (it = active_projections.begin(); it != end; ++it) {
		(*it)->Resize();
	}
}

std::vector<Projection*> Projection::active_projections =
	std::vector<Projection*>();

int Projection::window_height = 0;
int Projection::window_width = 0;

