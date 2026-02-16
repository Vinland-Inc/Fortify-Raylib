#pragma once
#include <vector>
#include "raylib.h"

class Enemy
{
  public:
    Enemy();
	~Enemy();

	void process();
    void init(Vector2 spawnPosition, std::vector<Vector2> wayPath);

  private:
    const float MIN_DISTANCE_TO_POINT = 2.5f;
    float x = 0;
    float y = 0;
    int currentPoint = 0;
    Vector2 spawnPosition = {0,0};
    const float speed = 100.0f;
    Vector2 direction = {0,0};
    std::vector<Vector2> wayPath;
};
