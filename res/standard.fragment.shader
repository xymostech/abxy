#version 330

smooth in vec4 theColor;
smooth in vec2 theTexCoord;

uniform sampler2D textureSampler;

uniform int useTexture;

out vec4 outputColor;

void main()
{
	if (useTexture == 0) {
		outputColor = theColor;
	} else {
		outputColor = texture(textureSampler, theTexCoord);
	}
}
