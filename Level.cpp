//
// Created by rezznov on 13/04/17.
//


#include "Level.h"
#include <fstream>
#include <iostream>
#include "ResourceManager.h"

Level::Level(const std::string& fileName){


    std::ifstream file;
    file.open(fileName);

    //Error checking
    if(file.fail()){
        //Bengine::fatalError("Failed to open " + fileName);
        std::cout << "no se encontro archivo" << std::endl;
    }


    //throw away the first string in tmp
    std::string tmp;
    file >> tmp >> _numHumans;

    while (std::getline(file, tmp)){

        _levelData.push_back(tmp);
    }

    /*
    std::cout<< "hola" << std::endl;
    //print for test
    for(int i = 0; i < _levelData.size(); i++){
        std::cout << _levelData[i] << "debe haber algo"<< std::endl;
    }*/
//    _spriteBatch.init();
//    _spriteBatch.begin();
//
//    glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
//
//    Bengine::ColorRGBA8 whiteColor;
//    whiteColor.r = 255;
//    whiteColor.g = 255;
//    whiteColor.b = 255;
//    whiteColor.a = 255;
//
//    // Render all the tiles
//    for (int y = 0; y < _levelData.size(); y++) {
//        for (int x = 0; x < _levelData[y].size(); x++) {
//            // Grab the tile
//            char tile = _levelData[y][x];
//
//            // Get dest rect
//            glm::vec4 destRect(x * TILE_WIDTH, y * TILE_WIDTH, TILE_WIDTH, TILE_WIDTH);
//
//            // Process the tile
//            switch (tile) {
//                case 'B':
//                case 'R':
//                    _spriteBatch.draw(destRect,
//                                      uvRect,
//                                      Bengine::ResourceManager::getTexture("red_bricks.png").id,
//                                      0.0f,
//                                      whiteColor);
//                    break;
//                case 'G':
//                    _spriteBatch.draw(destRect,
//                                      uvRect,
//                                      Bengine::ResourceManager::getTexture("glass.png").id,
//                                      0.0f,
//                                      whiteColor);
//                    break;
//                case 'L':
//                    _spriteBatch.draw(destRect,
//                                      uvRect,
//                                      Bengine::ResourceManager::getTexture("light_bricks.png").id,
//                                      0.0f,
//                                      whiteColor);
//                    break;
//                case '@':
//
//                    break;
//                case 'Z':
//
//                    break;
//                case '.':
//                    break;
//                default:
//                    std::printf("Unexpected symbol %c at (%d,%d)", tile, x, y);
//                    break;
//            }
//        }
//    }
//
//    _spriteBatch.end();



}

Level::~Level(){

}

void Level::draw(){
//    _spriteBatch.renderBatch();
}
