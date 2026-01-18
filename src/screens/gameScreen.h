#pragma once
#include <iostream>
#include "raylib.h"
#include "playerCamera.h"


class GameScreen
{
  public:
    GameScreen();
    ~GameScreen();

    void process();

  private:
    Texture2D tileMap; // это вся карта
    Texture2D tile;    // это одна плитка
    PlayerCamera *playerCamera;
};
