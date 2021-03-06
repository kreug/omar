#version 330 core
layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTexCoords;
layout (location = 2) in vec3 aTextColor;
layout (location = 3) in vec3 aTileColor;

out vec2 texCoords;
out vec3 textColor;
out vec3 tileColor;

uniform mat4 projection;
uniform mat4 fontProjection;

void main()
{
	gl_Position = projection * vec4(aPos, 0.0f, 1.0f);
	vec4 texCoordsProjected = fontProjection * vec4(aTexCoords, 0.0f, 1.0f);
	texCoords = vec2(texCoordsProjected.x, texCoordsProjected.y);
	textColor = aTextColor;
	tileColor = aTileColor;

}
