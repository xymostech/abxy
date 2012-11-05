#version 330

smooth in vec2 theTexCoord;

uniform vec4 font_color;

uniform sampler2D textureSampler;

uniform ivec2 texture_size;
uniform ivec2 texture_offset;

out vec4 outputColor;

void main() {
	vec2 coord = vec2((theTexCoord.x + texture_offset.x) / float(texture_size.x),
                          (theTexCoord.y + texture_offset.y) / float(texture_size.y));
	float alpha = texture(textureSampler, coord).r;
	outputColor = vec4(1, 1, 1, alpha);
}
