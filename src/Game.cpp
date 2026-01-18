#include "Game.h"

Game::Game() : isRunning(true), state(MENU), FPS(60)
{	
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
	menu = new MenuScreen(); 
    gameScreen = new GameScreen();

	menu->on("play_clicked", [this]() { 
		std::cout << "play button was clicked\n";
		state = GAME;
	});

	menu->on("settings_clicked", [this]() {
		std::cout << "settings clicked\n";
	});

	menu->on("exit_clicked", [this]() {
		isRunning = false; 
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
            gameScreen->process();
			break;
		case PAUSE:
			break;
		}

		EndDrawing();
	}
}

Game::~Game()
{
	if (menu) //может быть исключение, если указатель не указывает на что либо, если будем в будущем отчищать их как-либо, то сразу устанвливаем в nullptr, иначе эта проверка не сработает 
		delete menu;
	if (gameScreen)
		delete gameScreen;
	CloseAudioDevice();
	CloseWindow();
}
