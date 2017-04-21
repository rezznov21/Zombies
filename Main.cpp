#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <IL/il.h>
#include "Camera.h"
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Texture2D.h"
#include "Transform.h"
#include <iostream>
#include <vector>
#include "Level.h"
#include "Cube.h"
#include <random>

Mesh _mesh;
Mesh _mesh2;
ShaderProgram _shaderProgram;
Transform _transform;
Texture2D _texture;

Camera _camera;

std::vector<Cube*> _cubes;
std::vector<Level*> _levels;
std::vector<std::string> stdMapa;
Cube* _cubito = new Cube();

void Initialize()
{

    //_cubito->init();

    //_transform.SetPosition(1.0f, 0.0f, 0.0f);

    _shaderProgram.CreateProgram();
    _shaderProgram.Activate();
    _shaderProgram.AttachShader("DefaultTransform.vert", GL_VERTEX_SHADER);
    _shaderProgram.AttachShader("Default.frag", GL_FRAGMENT_SHADER);
    _shaderProgram.SetAttribute(0, "VertexPosition");
    _shaderProgram.SetAttribute(1, "VertexColor");

    _shaderProgram.LinkProgram();
    _shaderProgram.Deactivate();


    _camera.SetPerspective(1.0f, 1000.0f, 60.0f, 1.0f);
    _camera.SetPosition(1.0f, 0.0f, -50.0f);

    std::mt19937 randomEngine;
    randomEngine.seed(time(nullptr));
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd());//Standard mersenne_twister_engine seeded with rd()

    std::uniform_int_distribution<int> randX(2, 20);
    std::uniform_int_distribution<int> randY(2, 20);

    

    for (int i = 0; i < 10; i++){

        _cubes.push_back(new Cube);
        glm::vec2 pos(randX(gen), randY(gen));
        std::cout << "la posicion de x: " << pos.x << std::endl;
        _cubes.back()->init(2.0f, pos);

    }




}


int index = 0;
//std::vector<Transform> Tarray;
Transform Tarray[200];
void createTransforms(){
   /* _shaderProgram.SetUniformMatrix("ModelMatrix", Tarray[index].GetModelMatrix());
    _shaderProgram.SetUniformMatrix("NormalMatrix", glm::mat3(glm::transpose(glm::inverse(Tarray[index].GetModelMatrix()))));
    _shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * Tarray[index].GetModelMatrix());
    _mesh.Draw(GL_TRIANGLES);
    Tarray[index].SetPosition(1.0f, 0.0f, 0.0f);
    Tarray[index].SetScale(4.0f,4.0f,4.0f);
    // std::printf("Se creo cubo");
    std::cout << "Se hizo cubo" << std::endl;*/
}


void Idle()
{
    glutPostRedisplay();
}

void GameLoop()
{

    // Siempre es recomendable borrar la información anterior del framebuffer.
    // En este caso estamos borrando la información de color,
    // y la información de profundidad.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::vec3 camPos = _camera.GetPosition();

    _shaderProgram.Activate();


    //_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _cubito->getModelMatrix());

    for(int i = 0; i < _cubes.size(); i++){
        _shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _cubes[i]->getModelMatrix());

        _cubes[i]->draw();
    }
    //_cubito->draw();

   _shaderProgram.Deactivate();

    // Cambiar el buffer actual.
    glutSwapBuffers();
}

void Keyboard(unsigned char key, int x, int y){



    if(key == 'w') {
        _camera.MoveForward(0.1f, false);
    }
    if(key == 's') {
        _camera.MoveForward(-0.1f, false);
    }
    if(key == 'd') {
        _camera.MoveRight(0.1f, false);
    }
    if(key == 'a') {
        _camera.MoveRight(-0.1f, false);
    }

}



void SpecialKeys(int key, int x, int y){

    if(key == GLUT_KEY_UP){
        _transform.MoveForward(0.1f, true);
    }
    if(key == GLUT_KEY_DOWN){
        _transform.MoveForward(-0.1f, true);
    }
    if(key == GLUT_KEY_RIGHT){

    }
    if(key == GLUT_KEY_LEFT){

    }


}

int _previousX = -1;
bool _mousePressed = false;
void MouseButtons(int button, int state, int x, int y){

    if(button == GLUT_LEFT_BUTTON){
        if(state == GLUT_DOWN) {

            _mousePressed = true;
        }else if(state == GLUT_UP){
            _mousePressed = false;

        }
        _previousX = x;
    }

    if(button == GLUT_LEFT_BUTTON) {
        _transform.MoveForward(0.1f, true);
    }
    if(button == GLUT_RIGHT_BUTTON){
        _transform.MoveForward(-0.1f,true);
    }

}

void MouseMotion(int x, int y){

    if(!_mousePressed) return;
    _camera.Yaw((x - _previousX) * 0.1f);
    _previousX = x;

}

void MousePassiveMotion(int x, int y){

    int centerX = glutGet(GLUT_WINDOW_WIDTH)/2;
    int centerY = glutGet(GLUT_WINDOW_HEIGHT)/2;
    int deltaX = x - centerX;

    _camera.Rotate(0.0f, -deltaX * 0.01f, 0.0f, true);

    if(deltaX){
        glutWarpPointer(centerX, centerY);
    }

}

void ReshapeWindow(int width, int height){

    glViewport(0,0, width, height);
    _camera.SetPerspective(1.0f, 1000.0f, 60.0f, (float) width/(float) height);

}



int main(int argc, char* argv[])
{
    // Inicialización de Freeglut.
    // Freeglut se encarga de crear una ventana
    // En donde vamos a poder dibujar
    glutInit(&argc, argv);
    // Freeglut es el encargado de solicitar un contexto
    // de OpenGL. El contexto se refiere a las capacidades
    // que va a tener nuestra aplicación gráfica.
    glutInitContextVersion(4, 4);
    // Tenemos que informar que queremos trabajar únicamente con
    // el pipeline programable
    glutInitContextProfile(GLUT_CORE_PROFILE);
    // Freeglut nos permite configurar eventos que ocurren en la venta.
    // Un evento que nos interesa es cuando alguien cierra la venta.
    // En este caso simplemente dejamos de renderear y terminamos el programa.
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
    // Configuramos el framebuffer. En este caso estamos solicitando
    // un buffer true color RGBA, un buffer de profundidad y un segundo buffer
    // para renderear.
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(800, 800);
    // Le damos un nombre a la ventana y la creamos.
    glutCreateWindow("Zombie Game");
    // Asociamos una funcion de render. Esta función se
    // mandará a llamar para dibujar un frame.

    _levels.push_back(new Level("pruebaLevel.txt"));
    stdMapa = _levels.front()->_levelData;
    //drawMap();
    //_levels.front()->draw();
    glutDisplayFunc(GameLoop);
    glutIdleFunc(Idle);
    glutKeyboardFunc(Keyboard);
    glutSpecialFunc(SpecialKeys);
    //glutMouseFunc(MouseButtons);
    //glutMotionFunc(MouseMotion);



    //glutPassiveMotionFunc(MousePassiveMotion);

    int centerX = glutGet(GLUT_WINDOW_WIDTH)/2;
    int centerY = glutGet(GLUT_WINDOW_HEIGHT)/2;
    glutWarpPointer(centerX, centerY);
    glutReshapeFunc(ReshapeWindow);

    // Inicializar GLEW. Esta librería se encarga
    // de obtener el API de OpenGL de nuestra tarjeta
    // de video. SHAME ON YOU MICROSOFT.
    glewExperimental = GL_TRUE;
    glewInit();

    // Configuramos OpenGL. Este es el color
    // por default del buffer de color en el framebuffer.
    glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
    glEnable(GL_DEPTH_TEST);
   glEnable(GL_CULL_FACE);

    // Inicializar DevIL
    ilInit(); // Inicializamos la librería y sus recursos
    ilEnable(IL_ORIGIN_SET); // Le decimos que queremos cambiar
    // el punto de origen
    ilOriginFunc(IL_ORIGIN_LOWER_LEFT); // Cambiarlo y configurarlo
    // como abajo a la izquerda. Hace match con las
    // coordenadas de textura.

    Initialize();

    // Iniciar la aplicación. El main se pausará en esta
    // línea hasta que se cierre la ventana de OpenGL.
    glutMainLoop();

    // Terminar.
    return 0;
}
