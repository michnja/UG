// Vertex shader
#version 330 core

// Dane pobrane z VAO
layout (location = 0) in vec4 inPosition;
layout (location = 1) in vec3 inColor;
layout (location = 2) in float inSize;

// Predefiniowane dane wejsciowe
//in int gl_VertexID;
//in int gl_InstanceID;

// Dane wyjsciowe (kolejny etap potoku)
//out vec4 gl_Position;
out vec3 Kolor;
// out vec2 Size;

void main()
{
      gl_PointSize = inSize;
      Kolor = inColor;
	gl_Position = inPosition;
}