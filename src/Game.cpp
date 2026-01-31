#include "Game.h"

Game::Game() : isRunning(true), state(MENU), FPS(60), backgroundColor(BLACK)
{	
	initWindow();
	InitAudioDevice();
	initMenu();
	initLevels();
	gameScreen = new GameScreen();
}

void Game::initWindow()
{
    SetConfigFlags(FLAG_WINDOW_UNDECORATED); // убирает рамки окна, мб поможет решить проблему с зависанием игры
    int monitor = GetCurrentMonitor();
    InitWindow(GetMonitorWidth(monitor), GetMonitorHeight(monitor), "Fortify");
    SetTargetFPS(FPS);
}

void Game::initMenu()
{
	menu = new MenuScreen(); 

	menu->on("play_clicked", std::function<void()>([this]() {
		std::cout << "play button was clicked\n";
		levelsScreen->activate();
		state = LEVELS;
	}));

	menu->on("settings_clicked", std::function<void()>([this]() {
		std::cout << "settings clicked\n";
	}));

	menu->on("exit_clicked", std::function<void()>([this]() {
		isRunning = false; 
	}));
}

void Game::initLevels()
{
	levelsScreen = new LevelsScreen();
	levelsScreen->on("level_clicked", std::function<void(int)>([this](int levelNumber) {
		std::cout << "Selected level: " << levelNumber << '\n';
		gameScreen->activate();
		gameScreen->mapInit(LevelConfig::GetConfigById(levelNumber));
		state = GAME;
	}));
}

void Game::Run() 
{
	while (!WindowShouldClose() && isRunning) {
		BeginDrawing();
		ClearBackground(backgroundColor);

		if (IsKeyPressed(KEY_M)) // на время дебага
            state = MENU;

		switch (state)
		{
		case MENU:
			backgroundColor = menu->backgroundColor;
			menu->process();
			break;
		case LEVELS:
			backgroundColor = levelsScreen->backgroundColor;
			levelsScreen->process();
			break;
		case GAME:
			backgroundColor = gameScreen->backgroundColor;
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
	if (gameScreen)
		delete gameScreen;
	if (levelsScreen)
		delete levelsScreen;
	if (menu)
		delete menu;
	CloseAudioDevice();
	CloseWindow();
}
