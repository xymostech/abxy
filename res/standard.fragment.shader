#version 140

smooth in vec4 theColor;
smooth in vec2 theTexCoord;

uniform sampler2D textureSampler;

uniform int blend_style;

out vec4 outputColor;

void main()
{
	if (blend_style == 0) {
		outputColor = theColor;
	} else if (blend_style == 1) {
		outputColor = texture(textureSampler, theTexCoord);
	} else {
		outputColor = texture(textureSampler, theTexCoord) * theColor;
	}
}
