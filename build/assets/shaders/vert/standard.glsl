#version 330 core
layout (location = 0) in vec3 aPos;

uniform vec2 u_resolution;
uniform vec2 u_position;
uniform vec2 u_size;
uniform float u_depth;

void main()
{
//  ranslation matrix
//  the aPos is 1 or 0 for every point in squre so i know if i should add size to the point or not
    mat4 translationMatrix = mat4(
    1.0, 0.0, 0.0, u_position.x + (u_size.x * aPos.x),
    0.0, 1.0, 0.0, u_position.y + (u_size.y * aPos.y),
    0.0, 0.0, 1.0, u_depth,
    0.0, 0.0, 0.0, 1.0
    );

//  scaling matrinx
    mat4 scalingMatrix = mat4(
    1/(0.5*u_resolution.x), 0.0, 0.0, -1.0,
    0.0, -1/(0.5*u_resolution.y), 0.0, 1.0,
    0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0
    );


    mat4 tranformationMatrix = (translationMatrix * scalingMatrix);
    gl_Position.x = tranformationMatrix[0][3];
    gl_Position.y = tranformationMatrix[1][3];
    gl_Position.z = tranformationMatrix[2][3];
    gl_Position.w = tranformationMatrix[3][3];
}