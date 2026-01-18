#include "Game.h"

Game::Game()
{
	isRunning = true;
	state = MENU;
	FPS = 60;
	
	initWindow();
	InitAudioDevice();
	initMenu();
}

void Game::initWindow()
{
	SetConfigFlags(FLAG_FULLSCREEN_MODE);
	InitWindow(0, 0, "Fortify");
	SetTargetFPS(FPS);
}

void Game::initMenu()
{
	menu = new MenuScreen(); //не помню, как malloc пишется, можешь поменять // блять я еще не ебу что такое малок. Но я знаю Рому Малека из сериала Мистер Робот.
    game = new GameScreen(); //не помню, как malloc пишется, можешь поменять // блять я еще не ебу что такое малок. Но я знаю Рому Малека из сериала Мистер Робот.

	menu->on("play_clicked", [this]() { //потом спроси у меня, че this тут делает
		std::cout << "play button was clicked\n";
		state = GAME;
	});

	menu->on("settings_clicked", [this]() {
		std::cout << "settings clicked\n";
	});

	menu->on("exit_clicked", [this]() {
		isRunning = false; //цикл заканчивается нахуй
	});
}

void Game::Run() //главный while-цикл думаю лучше всего оставить тут
{
	while (!WindowShouldClose() && isRunning) {
		BeginDrawing();

		switch (state)
		{
		case MENU:
			menu->process();
			break;
		case GAME:
            game->process();
			break;
		case PAUSE:
			break;
		}

		EndDrawing();
	}
}

Game::~Game()
{
	delete menu;
	CloseAudioDevice();
	CloseWindow();
}
