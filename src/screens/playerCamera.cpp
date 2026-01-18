#include "playerCamera.h"

PlayerCamera::PlayerCamera()
{
    cameraInit();
    cameraBeenZoomed = false;
}

void PlayerCamera::cameraInit()
{
    camera = {0};
    camera.target = {0.0f, 0.0f}; // тока в мире, на которую смотрит камера
    camera.offset = {(float)GetScreenWidth() / 2.0f, (float)GetScreenHeight() / 2.0f}; // смещение относительно target, пишу так чтобы был в центре
    camera.zoom = 0.2f;                                // масштаб камеры (чем больше тем ближе)
    camera.rotation = 0.0f;                            // угол поворота камеры

    cameraSpeed = CAMERA_DEFAULT_SPEED;
    maxCameraZoom = 3.0f;
    minCameraZoom = 1.0f;
}

void PlayerCamera::cameraInputHandler()
{
    cameraSpeed = IsKeyDown(KEY_LEFT_SHIFT) ? CAMERA_SHIFT_PRESSED_SPEED : CAMERA_DEFAULT_SPEED;

    float wheel = GetMouseWheelMove();
    if (wheel != 0)
    {
        camera.zoom += wheel * 0.1f;
        camera.zoom = Clamp(camera.zoom, minCameraZoom, maxCameraZoom);
    }
}

void PlayerCamera::zoomCamera()
{
    // приближается до тех пор пока не достигнет максимального зума
    if (camera.zoom < maxCameraZoom)
    {
        camera.zoom += zoomSpeed * GetFrameTime() * 0.1;
    }
    else 
        cameraBeenZoomed = true;
}

void PlayerCamera::setCameraTarget(Vector2 target)
{
    camera.target = target;
}

void PlayerCamera::move(Vector2 delta)
{
    if (!cameraBeenZoomed)
        return;

    if (delta.x != 0 || delta.y != 0)
    {
        float dt = GetFrameTime();
        delta = Vector2Normalize(delta);
        camera.target.x += delta.x * cameraSpeed * dt;
        camera.target.y += delta.y * cameraSpeed * dt; //вместо двух операций GetFrameTime, как было, стала одна, это оптимизация, брат
    }
}

void PlayerCamera::process()
{
    cameraInputHandler();
}

PlayerCamera::~PlayerCamera()
{

}
