#version 330

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texcoord;

uniform mat4 model_to_world_matrix;

smooth out vec2 theTexCoord;

layout(std140) uniform matrices
{
	mat4 camera_to_clip_matrix;
	mat4 world_to_camera_matrix;
};

void main() {
	gl_Position = camera_to_clip_matrix * world_to_camera_matrix * model_to_world_matrix * position;
	theTexCoord = texcoord;
}
