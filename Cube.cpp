//
// Created by rezznov on 13/04/17.
//
#include "Level.h"
#include "Cube.h"
#include "Mesh.h"
#include "Transform.h"
#include "ShaderProgram.h"
#include "Texture2D.h"
#include <fstream>
#include <iostream>


Cube::Cube() {


}
void Cube::init(float speed, glm::vec2 positionGrid){
    std::vector<unsigned int> indices{0, 1, 2, 0, 2, 3};
    _positions.push_back(glm::vec3(0.0f, 0.0f, 0.0f));   //cuadro1
    _positions.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
    _positions.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
    _positions.push_back(glm::vec3(0.0f, 1.0f, 0.0f));

    _mesh.CreateMesh(4);
    _mesh.SetPositionAttribute(_positions, GL_STATIC_DRAW, 0);
    _mesh.SetIndices(indices, GL_STATIC_DRAW);
    _transform.SetPosition(positionGrid.x, positionGrid.y,0.0f); }

void Cube::draw() {

    _mesh.Draw(GL_TRIANGLES);
}

glm::mat4 Cube::getModelMatrix(){

    return _transform.GetModelMatrix();

}


