#pragma once
#include "../Extensions.h"
#include "../audio/SoundPlayer.h"
#include "../eventhandler/EventHandler.h"
#include "raylib.h"

class MenuScreen final : public EventHandler
{
  private:
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    void handleClickOnButton();
    void render();
    void setupButton(extensions::Button &button, float yPosition);

    SoundPlayer clickSound;

    extensions::Button playButton;
    extensions::Button optionsButton;
    extensions::Button exitButton;

    float buttonSpacing = 25;
    float buttonScale = 2.5f;

  public:
    Color backgroundColor;

    MenuScreen();
    ~MenuScreen();

    void process();
};
