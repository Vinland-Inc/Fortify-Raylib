#include <cmath> // для правильного округления позиции мыши
#include <fstream> // для чтения файла
#include "gameScreen.h"

GameScreen::GameScreen() : isMovingByMouse(false), backgroundColor(DARKGRAY), lastPos({})
{
    mapInit(LevelConfig::GetConfigById(1));

    playerCamera = new PlayerCamera;
    playerCamera->setCameraTarget({float((map.size() / 2) * CELL_SIZE), float((map[0].size() / 2) * CELL_SIZE)});
    tileMap = LoadTexture("sprites/map/spritesheet.png");

    tileSourceRec = {CELL_SIZE - 1, (CELL_SIZE * 8) - 1, CELL_SIZE + 1, CELL_SIZE + 1};
}

void GameScreen::activate()
{
    playerCamera->cameraBeenZoomed = false;
    playerCamera->camera.zoom = 0.2f;
    playerCamera->setCameraTarget({float((map.size() / 2) * CELL_SIZE), float((map[0].size() / 2) * CELL_SIZE)});
}

void GameScreen::process()
{
    handleClick();
    handleInput();


    // примерно так будет выглядеть логика строительства туреллей, она уже работает расскоментируй чтобы тестануть
  
    //Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), playerCamera->camera); // перевод экранных координат в мировые
    //int mouseGridX = (int)floor(mouseWorldPos.x / CELL_SIZE);
    //int mouseGridY = (int)floor(mouseWorldPos.y / CELL_SIZE);
    //if (mouseGridX >= 0 && mouseGridY >= 0 && mouseGridX < map.size() && mouseGridY < map[0].size())
    //    colorrr = map[mouseGridX][mouseGridY] == TILE_WALL ? WHITE : RED;
    //else
    //    colorrr = RED;
    //DrawTexture(tileMap, GetMouseX() - tileMap.width / 2, GetMouseY() - tileMap.height / 2, colorrr);
    //DrawText(TextFormat("mouseX: %d\n\nmouseY: %d", mouseGridX, mouseGridY), 15, 50, 25, WHITE);


    BeginMode2D(playerCamera->camera);

    playerCamera->cameraBeenZoomed ? playerCamera->process() : playerCamera->zoomCamera();

    

    render();
    EndMode2D();
    DrawFPS(15, 15);
}

void GameScreen::handleClick()
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
    {
        isMovingByMouse = true; //движение начинается
        lastPos = GetMousePosition();
    }
    else if (IsMouseButtonReleased(MOUSE_BUTTON_RIGHT)) {
        isMovingByMouse = false; //движение прекращается
    }
}

void GameScreen::handleInput()
{
    if (isMovingByMouse) {
        Vector2 currentMousePos = GetMousePosition();

        playerCamera->move(Vector2{ -(currentMousePos.x - lastPos.x), -(currentMousePos.y - lastPos.y) }); //двигаем камеру в противоположную сторону от того, куда ведет юзер, поэтому минус

        lastPos = currentMousePos;
    } else {
        Vector2 delta = { 0, 0 };
        if (IsKeyDown(KEY_D))
            delta.x += 1.0f;
        if (IsKeyDown(KEY_A))
            delta.x -= 1.0f;
        if (IsKeyDown(KEY_W))
            delta.y -= 1.0f;
        if (IsKeyDown(KEY_S))
            delta.y += 1.0f;

        playerCamera->move(delta);
    }
}

void GameScreen::render()
{
    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            if (map[i][j] == TILE_WALL)
                DrawTextureRec(tileMap, tileSourceRec, Vector2{ (float)i * CELL_SIZE, (float)j * CELL_SIZE }, WHITE);
        }
    }
}

void GameScreen::mapInit(LevelConfig levelConfig)
{
    std::fstream file(levelConfig.mapPath);

    if (!file.is_open())
    {
        std::cerr << "Couldn't open the file for reading\n";
        return;
    }

    int mapWidth, mapHeight;
    file >> mapWidth >> mapHeight;

    map.resize(mapHeight);
    for (int y = 0; y < mapHeight; ++y)
        map[y].resize(mapWidth);

    for (int y = 0; y < mapHeight; y++)
    {
        for (int x = 0; x < mapWidth; x++)
        {
            file >> map[y][x];
        }
    }
}

GameScreen::~GameScreen()
{
    delete playerCamera;
}
