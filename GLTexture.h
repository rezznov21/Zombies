//
// Created by rezznov on 14/04/17.
//

#pragma once
#include <GL/glew.h>
#include <string>

namespace Bengine {

    struct GLTexture {
        std::string filePath = "";
        GLuint id;
        int width;
        int height;
    };
}
