#include "MenuScreen.h"

// это все дипсик написал, сам центруй свои ебаные кнопки даун

MenuScreen::MenuScreen() : EventHandler(), backgroundColor(BLACK) 
{
    clickSound.load("src/audio/click.wav");

    float startY = (GetScreenHeight() - (3 * 100 + 2 * buttonSpacing)) / 2;

    playButton.texture = LoadTexture("sprites/UI/buttons/Play_button.png");
    setupButton(playButton, startY);
    playButton.setClickSound(&clickSound);

    optionsButton.texture = LoadTexture("sprites/UI/buttons/Options_button.png");
    setupButton(optionsButton, startY + 100 + buttonSpacing);
    optionsButton.setClickSound(&clickSound);

    exitButton.texture = LoadTexture("sprites/UI/buttons/Exit_button.png");
    setupButton(exitButton, startY + 2 * (100 + buttonSpacing));
    exitButton.setClickSound(&clickSound);
}

void MenuScreen::setupButton(extensions::Button &button, float yPosition)
{
    float buttonWidth = button.texture.width / buttonScale;
    float buttonHeight = button.texture.height / buttonScale;

    button.rect = {(float)screenWidth / 2 - buttonWidth / 2, yPosition, buttonWidth, buttonHeight};
}

void MenuScreen::handleClickOnButton()
{
    if (playButton.isClicked())
    {
        emit("play_clicked");
    }
    else if (optionsButton.isClicked())
    {
        emit("settings_clicked");
    }
    else if (exitButton.isClicked())
    {
        emit("exit_clicked");
    }
}

void MenuScreen::render()
{
    playButton.render();
    optionsButton.render();
    exitButton.render();
}

void MenuScreen::process()
{
    playButton.hover();
    optionsButton.hover();
    exitButton.hover();

    handleClickOnButton();

    render();
}

MenuScreen::~MenuScreen()
{
}
