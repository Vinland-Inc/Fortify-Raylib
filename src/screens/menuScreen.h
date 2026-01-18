#pragma once
#include <iostream>
#include <functional> //это надо для std::function<void>, что-то типа предиката у вас
#include <map> //дефолтный map, который будет событие и функцию, которая должна быть вызвана на этот событие
#include "raylib.h"
#include "../Extensions.h"
#include "../audio/SoundPlayer.h"

class MenuScreen
{
private:
    Color menuBackground;

    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    void handleClickOnButton();

    //один обьект звука для всех кнопок
    SoundPlayer clickSound;

    extensions::Button playButton;
    extensions::Button optionsButton;
    extensions::Button exitButton;

    //map для хранения типа события и реакции на него (callback)
    std::map<std::string, std::function<void()>> callbacks;
public:
    MenuScreen();
    ~MenuScreen();

    void on(std::string event_type, std::function<void()> callback); //чтобы добавить реакцию на событие
    void emit(std::string event_type); //чтобы вызывать все реакции

    void process();
};
