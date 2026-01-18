#include "gameScreen.h"

GameScreen::GameScreen()
{
    playerCamera = new PlayerCamera;
}

void GameScreen::process()
{
    ClearBackground(DARKGRAY);

    BeginMode2D(playerCamera->camera); // это нужно чтобы всё рисовалось в мировых координатах
    playerCamera->process();

    DrawCircle(500, 500, 20, YELLOW);

    EndMode2D();
}

GameScreen::~GameScreen()
{
    delete playerCamera;
}
