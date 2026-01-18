#pragma once
#include "raylib.h"
#include "raymath.h" // для метода Vector2Normalize

#define CAMERA_DEFAULT_SPEED 600
#define CAMERA_SHIFT_PRESSED_SPEED 1500

class PlayerCamera
{
  public:
    PlayerCamera();
    ~PlayerCamera();
    Camera2D camera;

    void process();
    void zoomCamera();
    void setCameraTarget(Vector2 target);
    void move(Vector2 delta);

    bool cameraBeenZoomed;
  private:
    int cameraSpeed;
    float maxCameraZoom;
    float minCameraZoom;
    float zoomSpeed = 10.0f;

    void cameraInit();
    void cameraInputHandler();
};
