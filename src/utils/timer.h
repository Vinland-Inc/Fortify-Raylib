#pragma once
#include "raylib.h"

struct Timer
{
    float timeoutTime;
    float leftTime;

    void update();
    bool timeout() const; // потом обязательно надо будет сделать чтобы таймер посылал сигнал, чтобы не приходилось проверять в каждом кадре
    void reset();
};
