#version 140

in vec3 position;
in vec4 color;
in vec3 normal;

smooth out vec4 f_interp_color;

uniform vec3 light_dir;
uniform vec4 light_intensity;

uniform mat4 model_to_world_matrix;

layout(std140) uniform matrices
{
	mat4 camera_to_clip_matrix;
	mat4 world_to_camera_matrix;
};

void main() {
	gl_Position =
		camera_to_clip_matrix *
		world_to_camera_matrix *
		model_to_world_matrix *
		vec4(position, 1.0);

	vec3 cam_space_normal = normalize(
		mat3(
			world_to_camera_matrix *
			model_to_world_matrix
		) * normal
	);

	float incidence_angle = dot(cam_space_normal, light_dir);
	incidence_angle = clamp(incidence_angle, 0, 1);

	f_interp_color = light_intensity * color * incidence_angle;
	f_interp_color.w = 1.0;
}
