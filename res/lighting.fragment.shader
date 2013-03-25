#version 140

smooth in vec4 f_interp_color;

out vec4 final_color;

void main() {
	final_color = f_interp_color;
}
