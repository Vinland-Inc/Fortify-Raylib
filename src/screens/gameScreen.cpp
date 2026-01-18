#include "gameScreen.h"

GameScreen::GameScreen()
{
    playerCamera = new PlayerCamera;
    tileMap = LoadTexture("sprites/map/spritesheet.png");

    // тут не обращай внимания на + 1 или - 1, просто художник еблан
    tileSourceRec = {CELL_SIZE - 1, (CELL_SIZE * 8) - 1, CELL_SIZE + 1, CELL_SIZE + 1}; // сначала 1 раз направо, потом 8 раз вниз, и так находим нужный спрайт
}

void GameScreen::process()
{
    ClearBackground(DARKGRAY);
    
    BeginMode2D(playerCamera->camera); // это нужно чтобы всё рисовалось в мировых координатах, всё что внутри BeginMode2D и EndMode2D будет двигатся вместе с камерой

    // если камера не была приближена, то приближаем, и только после этого даем возможность управлять ею
    playerCamera->cameraBeenZoomed ? playerCamera->process() : playerCamera->zoomCamera();

    render();
    EndMode2D();
    DrawFPS(15, 15); // рисуется выше всех
}

void GameScreen::render()
{
    // я тут написал значения от минус 60 до плюс 60 чтобы центр карты был там же где центр мира, а не в точках 0,0 
    for (int i = -60; i < 60; i++) // тут надо бы с двумерного массива взять значения, пока что примерно вот так сделаю
    {
        for (int j = -40; j < 40; j++)
        {
            DrawTextureRec(tileMap, tileSourceRec, Vector2 {(float)i*CELL_SIZE, (float)j*CELL_SIZE}, WHITE); // тут будет рисоваться не одна плитка, иначе всё очень сильно сливатеся
        }
    }
    DrawText("FORTIFY", -50, 0, 20, YELLOW); // это здесь по приколу
}

GameScreen::~GameScreen()
{
    delete playerCamera;
}
