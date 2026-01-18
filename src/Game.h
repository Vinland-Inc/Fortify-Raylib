#pragma once
#include "screens/menuScreen.h"
#include "screens/gameScreen.h"

typedef enum { MENU, LEVELS, GAME, PAUSE } GameStates;

class Game
{
public: 
	Game();
	~Game();

	void Run();
private:
	void initWindow(); 
	void initMenu();

	bool isRunning;
	GameStates state; 
	int FPS;
	MenuScreen *menu; 
    GameScreen *gameScreen; //у нас класс Game, прошлое название выглядело так, будто бы это обьект Game, а не GameScreen, упростим жизнь читателям, ибо я сам запутался сначала
};
