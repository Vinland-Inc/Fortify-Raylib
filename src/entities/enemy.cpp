#include "enemy.h"
#include "raymath.h"

Enemy::Enemy()
{
}

void Enemy::init(Vector2 spawnPosition, std::vector<Vector2> wayPath)
{
    this->spawnPosition = spawnPosition;
    this->wayPath = wayPath;

    x = spawnPosition.x;
    y = spawnPosition.y;
}

void Enemy::process()
{
    if (Vector2Distance({(float)x, (float)y}, wayPath[currentPoint]) < MIN_DISTANCE_TO_POINT)
    {
        if (currentPoint < wayPath.size() - 1)
            ++currentPoint;
        else
            return;
    }

    direction = Vector2Subtract(wayPath[currentPoint], Vector2{x, y});

    direction = Vector2Normalize(direction);
    x += direction.x * GetFrameTime() * speed;
    y += direction.y * GetFrameTime() * speed;

    DrawRectangle(x, y, 15, 15, BLACK);
}

Enemy::~Enemy()
{
}
