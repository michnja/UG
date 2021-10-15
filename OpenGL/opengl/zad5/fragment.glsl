// Fragment shader
#version 330 core

// Predefiniowane dane wejsciowe
//in  vec4 gl_FragCoord;
//in  int  gl_PrimitiveID;

// Dane wyjsciowe
out vec4 outColor;


void main()
{
	if (gl_PrimitiveID == 0)
	outColor = vec4(0.0, 0.72, 0.36, 1.0);
	else if (gl_PrimitiveID == 1 || gl_PrimitiveID == 2  || gl_PrimitiveID == 3 ) 
	outColor = vec4(0.05, 0.30, 0.18, 1.0); 
	else if (gl_PrimitiveID == 4) 
	outColor = vec4(0.27,0.20,0.24, 1.0);
	else if (gl_PrimitiveID == 5 || gl_PrimitiveID == 6) 
	outColor = vec4(0.52,0.09,0.3, 1.0);
	else if (gl_PrimitiveID == 7 || gl_PrimitiveID == 8  ) 
	outColor = vec4(0.75,0.0,0.36, 1.0);
	outColor.r += gl_FragCoord.x/800; 
}