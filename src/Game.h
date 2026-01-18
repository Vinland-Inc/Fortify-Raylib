#pragma once
#include "screens/menuScreen.h"
#include "screens/gameScreen.h"

typedef enum { MENU, GAME, PAUSE } GameStates;

class Game
{
public: 
	Game();
	~Game();

	void Run();
private:
	void initWindow(); //функция, чтобы создать окно
	void initMenu();

	bool isRunning;
	GameStates state; //она инициализируется в конструкторе
	int FPS;
	MenuScreen *menu; //обсудим потом, но я пока сделаю так, чтобы самому контролировать, когда вызывается конструктор (если сделать простой переменной, то исключение, так он начинает рисовать кнопки на еще не созданном окне)
    GameScreen *game;
};
