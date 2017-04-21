//
// Created by rezznov on 13/04/17.
//


#pragma once

#include <string>
#include <vector>
#include "Mesh.h"
#include "Transform.h"
#include "ShaderProgram.h"
#include "Texture2D.h"
#include "Camera.h"
//#include <Bengine/SpriteBatch.h>




class Cube{

public:
    //Load the level
    Cube();
    ~Cube();

    void init();

    void draw();
    glm::mat4 getModelMatrix();

    Mesh _mesh;
    Camera _camera;
    ShaderProgram _shaderProgram;
    Transform _transform;
    Texture2D _texture;
    std::vector<glm::vec3> _positions;
    std::vector<glm::vec2> _texCoords;

private:


};