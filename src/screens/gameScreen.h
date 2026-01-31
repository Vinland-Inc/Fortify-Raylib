#pragma once
#include <iostream>
#include <vector>
#include "raylib.h"
#include "playerCamera.h"

#define CELL_SIZE 16
#define TILE_WALL 1

class GameScreen
{
  public:
    Color backgroundColor;

    GameScreen();
    ~GameScreen();

    void process();
    void render();
    int currentLevel;
  private:
    void handleClick();
    void handleInput(); //чтобы обработать нажатие клавиатуры

    std::vector<std::vector<int>> map;

    Texture2D tileMap;
    Rectangle tileSourceRec; // координаты одной плитки
    PlayerCamera *playerCamera;

    //Для движения
    bool isMovingByMouse;
    Vector2 lastPos;


    Color colorrr = WHITE; // эт цвет объекта строительства, потом уберем в какой нибудь BuildingManager
};
