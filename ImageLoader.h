//
// Created by rezznov on 14/04/17.
//

#pragma once
#include "GLTexture.h"

#include <string>

namespace Bengine {

    //Loads images into GLTextures
    class ImageLoader
    {
    public:
        static GLTexture loadPNG(std::string filePath);
    };

}
