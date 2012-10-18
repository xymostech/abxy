#version 330

smooth in vec4 theColor;
smooth in vec2 theTexCoord;

uniform sampler2D textureSampler;

out vec4 outputColor;

void main()
{
	outputColor = theColor;
	outputColor = texture(textureSampler, theTexCoord);
}
