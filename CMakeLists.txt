cmake_minimum_required(VERSION 3.6)
project(Zombies)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Main.cpp Camera.cpp Camera.h Default.frag
        Default.vert InputFile.cpp InputFile.h Mesh.cpp Mesh.h Shader.cpp
        Shader.h ShaderProgram.cpp ShaderProgram.h Transform.cpp Transform.h DefaultTextured.frag
        DefaultTextured.vert PhongShading.frag PhongShading.vert DefaultTransform.vert Texture2D.cpp
        Texture2D.h smiley.jpeg crate.png floor.jpg pyramid.png pruebaLevel.txt Level.h Level.cpp Cube.h Cube.cpp SpriteBatch.h SpriteBatch.cpp Vertex.h ResourceManager.h TextureCache.h GLTexture.h ResourceManager.cpp
        glass.png light_bricks.png red_bricks.png TextureCache.cpp ImageLoader.h ImageLoader.cpp MainGame.h MainGame.cpp)
add_executable(Zombies ${SOURCE_FILES})
target_link_libraries(Zombies -lglut -lGL -lGLU -lGLEW -lIL)