//
// Created by rezznov on 13/04/17.
//


#pragma once

#include <string>
#include <vector>
#include "SpriteBatch.h"

//#include <Bengine/SpriteBatch.h>


const int TILE_WIDTH = 64;

class Level{

public:
    //Load the level
    Level(const std::string& fileName);
    ~Level();
    std::vector<std::string> _levelData;
    void draw();

private:

    int _numHumans;
    Bengine::SpriteBatch _spriteBatch;
};
