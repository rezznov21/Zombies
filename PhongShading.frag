#version 330

in vec3 InterpolatedColor;
in vec3 InterpolatedNormal;
in vec3 PixelPosition;

out vec4 FragColor;

uniform vec3 LightPosition;
uniform vec3 LightColor;
uniform vec3 CameraPosition;

void main()
{
	// Ambient component
	vec3 ambient = 0.1f * LightColor;

	// Diffuse component
	vec3 L = normalize(LightPosition - PixelPosition);
	vec3 N = normalize(InterpolatedNormal);
	vec3 diffuse = max(dot(N, L), 0.0f) * LightColor;

	// Specular component
	vec3 R = reflect(-L, N);
	vec3 V = normalize(CameraPosition - PixelPosition);
	vec3 specular = pow(max(dot(V, R), 0.0f), 8) * LightColor;
	
	vec3 phong = (ambient + diffuse) * InterpolatedColor + specular * 0.5f;
	FragColor = vec4(phong, 1.0f);
}