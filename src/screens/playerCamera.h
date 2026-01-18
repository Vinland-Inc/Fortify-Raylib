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

  private:
    int cameraSpeed;
    float maxCameraZoom;
    float minCameraZoom;

    void cameraInit();
    void cameraInputHundler();
};
