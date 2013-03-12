#version 140

in vec4 position;
in vec4 color;

uniform mat4 model_to_world_matrix;

smooth out vec4 theColor;

layout(std140) uniform matrices
{
	mat4 camera_to_clip_matrix;
	mat4 world_to_camera_matrix;
};

void main()
{
	gl_Position = camera_to_clip_matrix * world_to_camera_matrix * model_to_world_matrix * position;

	theColor = color;
}
