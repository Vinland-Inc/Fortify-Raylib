#pragma once
#include "raylib.h"
#include "../eventhandler/EventHandler.h"
#include "../Extensions.h"
#include "../audio/SoundPlayer.h"

class MenuScreen final : public EventHandler //класс, который наследует логику реакции на события, final - т.е от него наследоваться уже низя
{
private:
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    void handleClickOnButton();
    void render();

    //один обьект звука для всех кнопок
    SoundPlayer clickSound;

    extensions::Button playButton;
    extensions::Button optionsButton;
    extensions::Button exitButton;
public:
    Color backgroundColor;

    MenuScreen();
    ~MenuScreen();

    void process();
};
