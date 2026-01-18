#pragma once
#include <iostream>
#include <vector>
#include "raylib.h"
#include "playerCamera.h"

#define CELL_SIZE 16 // потом уберем отсюда все что связано с картой
#define TILE_WALL 1

class GameScreen
{
  public:
    GameScreen();
    ~GameScreen();

    void process();
    void render();

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
};
