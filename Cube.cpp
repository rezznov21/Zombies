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
void Cube::init(){
    std::vector<unsigned int> indices{0, 1, 2, 0, 2, 3};
    _positions.push_back(glm::vec3(0.0f, 0.0f, 0.0f));   //cuadro1
    _positions.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
    _positions.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
    _positions.push_back(glm::vec3(0.0f, 1.0f, 0.0f));

    _mesh.CreateMesh(4);
    _mesh.SetPositionAttribute(_positions, GL_STATIC_DRAW, 0);
    _mesh.SetIndices(indices, GL_STATIC_DRAW);

}

void Cube::draw() {
    // Cara trasera
//    _positions.push_back(glm::vec3(-1.0f, -1.0f, -1.0));
//    _positions.push_back(glm::vec3(1.0f, -1.0f, -1.0f));
//    _positions.push_back(glm::vec3(1.0f, 1.0f, -1.0f));
//    _positions.push_back(glm::vec3(-1.0f, 1.0f, -1.0f));
//    // Cara derecha
//    _positions.push_back(glm::vec3(1.0f, -1.0f, -1.0f));
//    _positions.push_back(glm::vec3(1.0f, -1.0f, 1.0f));
//    _positions.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
//    _positions.push_back(glm::vec3(1.0f, 1.0f, -1.0f));
//    // Cara frontal
//    _positions.push_back(glm::vec3(1.0f, -1.0f, 1.0f));
//    _positions.push_back(glm::vec3(-1.0f, -1.0f, 1.0f));
//    _positions.push_back(glm::vec3(-1.0f, 1.0f, 1.0f));
//    _positions.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
//    // Cara izquierda
//    _positions.push_back(glm::vec3(-1.0f, -1.0f, 1.0f));
//    _positions.push_back(glm::vec3(-1.0f, -1.0f, -1.0f));
//    _positions.push_back(glm::vec3(-1.0f, 1.0f, -1.0f));
//    _positions.push_back(glm::vec3(-1.0f, 1.0f, 1.0f));
//    // Cara arriba
//    _positions.push_back(glm::vec3(-1.0f, 1.0f, -1.0f));
//    _positions.push_back(glm::vec3(1.0f, 1.0f, -1.0f));
//    _positions.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
//    _positions.push_back(glm::vec3(-1.0f, 1.0f, 1.0f));
//    // Cara abajo
//    _positions.push_back(glm::vec3(-1.0f, -1.0f, 1.0f));
//    _positions.push_back(glm::vec3(1.0f, -1.0f, 1.0f));
//    _positions.push_back(glm::vec3(1.0f, -1.0f, -1.0f));
//    _positions.push_back(glm::vec3(-1.0f, -1.0f, -1.0f));
//
//
//    _texCoords.push_back(glm::vec2(0.0f, 0.0f));
//    _texCoords.push_back(glm::vec2(1.0f, 0.0f));
//    _texCoords.push_back(glm::vec2(1.0f, 1.0f));
//    _texCoords.push_back(glm::vec2(0.0f, 1.0f));
//    _texCoords.push_back(glm::vec2(0.0f, 0.0f));
//    _texCoords.push_back(glm::vec2(1.0f, 0.0f));
//    _texCoords.push_back(glm::vec2(1.0f, 1.0f));
//    _texCoords.push_back(glm::vec2(0.0f, 1.0f));
//    _texCoords.push_back(glm::vec2(0.0f, 0.0f));
//    _texCoords.push_back(glm::vec2(1.0f, 0.0f));
//    _texCoords.push_back(glm::vec2(1.0f, 1.0f));
//    _texCoords.push_back(glm::vec2(0.0f, 1.0f));
//    _texCoords.push_back(glm::vec2(0.0f, 0.0f));
//    _texCoords.push_back(glm::vec2(1.0f, 0.0f));
//    _texCoords.push_back(glm::vec2(1.0f, 1.0f));
//    _texCoords.push_back(glm::vec2(0.0f, 1.0f));
//    _texCoords.push_back(glm::vec2(0.0f, 0.0f));
//    _texCoords.push_back(glm::vec2(1.0f, 0.0f));
//    _texCoords.push_back(glm::vec2(1.0f, 1.0f));
//    _texCoords.push_back(glm::vec2(0.0f, 1.0f));
//    _texCoords.push_back(glm::vec2(0.0f, 0.0f));
//    _texCoords.push_back(glm::vec2(1.0f, 0.0f));
//    _texCoords.push_back(glm::vec2(1.0f, 1.0f));
//    _texCoords.push_back(glm::vec2(0.0f, 1.0f));
//
//    std::vector<unsigned int> indices{0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7, 8, 9, 10, 8, 10, 11, 12, 13, 14, 12, 14, 15, 16, 17, 18, 16, 18, 19, 20, 21, 22, 20, 22, 23};



    //_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
    //_mesh.SetNormalAttribute(normals, GL_STATIC_DRAW, 2);
    //_mesh.SetTexCoordAttribute(_texCoords, GL_STATIC_DRAW, 3);


//    _shaderProgram.CreateProgram();
//    _shaderProgram.Activate();
//    _shaderProgram.AttachShader("DefaultTextured.vert", GL_VERTEX_SHADER);
//    _shaderProgram.AttachShader("DefaultTextured.frag", GL_FRAGMENT_SHADER);
//    _shaderProgram.SetAttribute(0, "VertexPosition");
//    _shaderProgram.SetAttribute(1, "VertexColor");
//    _shaderProgram.SetAttribute(2, "VertexNormal");
//    _shaderProgram.SetAttribute(3, "VertexTexCoord");
//    _shaderProgram.LinkProgram();
//    _shaderProgram.Deactivate();
//    _texture.LoadTexture("crate.png");

//    _shaderProgram.Activate();
//
//    _texture.Bind();
//    glActiveTexture(GL_TEXTURE0);
//    _shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix());
//    _shaderProgram.SetUniformMatrix("NormalMatrix", glm::mat3(glm::transpose(glm::inverse(_transform.GetModelMatrix()))));
//    _shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix());

//    _texture.Unbind();
//    _shaderProgram.Deactivate();
    _mesh.Draw(GL_TRIANGLES);
}

glm::mat4 Cube::getModelMatrix(){

    return _transform.GetModelMatrix();

}
