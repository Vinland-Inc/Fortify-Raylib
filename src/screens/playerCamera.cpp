#include "playerCamera.h"

PlayerCamera::PlayerCamera()
{
    cameraInit();
}

void PlayerCamera::cameraInit()
{
    camera = {0};
    camera.target = {0.0f, 0.0f}; // тока в мире, на которую смотрит камера
    camera.offset = {(float)GetScreenWidth() / 2.0f, (float)GetScreenHeight() / 2.0f}; // смещение относительно target, пишу так чтобы был в центре
    camera.zoom = 1.0f;                                // масштаб камеры (чем больше тем ближе)
    camera.rotation = 0.0f;                            // угол поворота камеры

    cameraSpeed = CAMERA_DEFAULT_SPEED;
    maxCameraZoom = 3.0f;
    minCameraZoom = 0.3f;
}

void PlayerCamera::cameraInputHundler()
{
    Vector2 move = {0, 0};
    if (IsKeyDown(KEY_D))
        move.x += 1.0f;
    if (IsKeyDown(KEY_A))
        move.x -= 1.0f;
    if (IsKeyDown(KEY_W))
        move.y -= 1.0f;
    if (IsKeyDown(KEY_S))
        move.y += 1.0f;

    cameraSpeed = IsKeyDown(KEY_LEFT_SHIFT) ? CAMERA_SHIFT_PRESSED_SPEED : CAMERA_DEFAULT_SPEED;

    float wheel = GetMouseWheelMove();
    if (wheel != 0)
    {
        camera.zoom += wheel * 0.1f;
        camera.zoom = Clamp(camera.zoom,minCameraZoom, maxCameraZoom);
    }

    if (move.x != 0 || move.y != 0)
    {
        move = Vector2Normalize(move); // нормализует движение по диагонали
        camera.target.x += move.x * cameraSpeed * GetFrameTime();
        camera.target.y += move.y * cameraSpeed * GetFrameTime();
    }
}

void PlayerCamera::process()
{
    cameraInputHundler();
}

PlayerCamera::~PlayerCamera()
{

}
