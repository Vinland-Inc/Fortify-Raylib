#include "MenuScreen.h"

MenuScreen::MenuScreen()
{
    clickSound.load("src/audio/click.wav");
    menuBackground = BLACK;

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

void MenuScreen::process()
{
    playButton.hover();
    optionsButton.hover();
    exitButton.hover();

    handleClickOnButton();

    ClearBackground(menuBackground);

    playButton.render();
    optionsButton.render();
    exitButton.render();
}

void MenuScreen::on(std::string event_type, std::function<void()> callback)
{
    callbacks.emplace(event_type, callback); //будь уверен, что есть лишь одна реакция на одно событие, иначе пизда // почему? часто бывает что много объектов должны получить и обработать сигнал
}

void MenuScreen::emit(std::string event_type)
{
    if (callbacks.contains(event_type)) {
        auto& callback = callbacks[event_type];
        callback(); //вызываем говно 
    }
}

MenuScreen::~MenuScreen() //внутри button деструктор удаляет текстуру
{

}
