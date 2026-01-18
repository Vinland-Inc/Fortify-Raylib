#pragma once
#include <iostream>
#include "raylib.h"
#include "playerCamera.h"

#define CELL_SIZE 16 // потом уберем отсюда все что связано с картой

class GameScreen
{
  public:
    GameScreen();
    ~GameScreen();

    void process();
    void render();

  private:
    Texture2D tileMap;
    Rectangle tileSourceRec; // координаты одной плитки
    PlayerCamera *playerCamera;
};
