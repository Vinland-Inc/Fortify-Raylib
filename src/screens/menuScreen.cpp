#include "MenuScreen.h"

MenuScreen::MenuScreen() : EventHandler(), backgroundColor(BLACK)
{
    clickSound.load("src/audio/click.wav");

    playButton.texture = LoadTexture("sprites/UI/buttons/Play_button.png");
    playButton.rect = {
        (float)screenWidth / 2 - (float)playButton.texture.width / 4,
        (float)screenHeight / 4,
        (float)playButton.texture.width / 2.5f,
        (float)playButton.texture.height / 2.5f
    };
    playButton.setClickSound(&clickSound);

    optionsButton.texture = LoadTexture("sprites/UI/buttons/Options_button.png");
    optionsButton.rect = {
        (float)screenWidth / 2 - (float)optionsButton.texture.width / 4.35f,
        (float)screenHeight / 2.7f,
        (float)optionsButton.texture.width / 2.5f,
        (float)optionsButton.texture.height / 2.5f 
    };
    optionsButton.setClickSound(&clickSound);

    exitButton.texture = LoadTexture("sprites/UI/buttons/Exit_button.png");
    exitButton.rect = {
        (float)screenWidth / 2 - (float)exitButton.texture.width / 4,
        (float)screenHeight / 2.045f,
        (float)exitButton.texture.width / 2.5f,
        (float)exitButton.texture.height / 2.5f 
    };
    exitButton.setClickSound(&clickSound);
}

void MenuScreen::handleClickOnButton()
{
    if (playButton.isClicked()) {
        emit("play_clicked");
    } else if (optionsButton.isClicked()) {
        emit("settings_clicked");
    } else if (exitButton.isClicked()) {
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

MenuScreen::~MenuScreen() //внутри button деструктор удаляет текстуру
{

}
