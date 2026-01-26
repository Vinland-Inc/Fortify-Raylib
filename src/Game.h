#pragma once
#include "screens/menuScreen.h"
#include "screens/gameScreen.h"
#include "screens/levelsScreen.h"

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
	void initLevels();

	Color backgroundColor;
	bool isRunning;
	GameStates state; 
	int FPS;
	MenuScreen *menu; 
	LevelsScreen* levelsScreen;
    GameScreen *gameScreen;
};
