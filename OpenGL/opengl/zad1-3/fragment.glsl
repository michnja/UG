// Fragment shader
#version 330 core

// Predefiniowane dane wejsciowe
//in  vec4 gl_FragCoord;
//in  int  gl_PrimitiveID;

// Dane wyjsciowe
out vec4 outColor;
in vec3 Kolor;

void main()
{

	outColor = vec4(Kolor, 1.0);

} 