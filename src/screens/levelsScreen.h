#pragma once
#include "raylib.h"
#include "../Extensions.h"
#include "../eventhandler/EventHandler.h"

#define LEVEL_BUTTON_WIDTH 400
#define LEVEL_BUTTON_HEIGHT 200

class Level final : public extensions::Button { //final значит, что нельзя наследоваться от этого класса дальше
public: 
	int levelNumber;
	std::string name;
	bool isClosed;

	Level();
	~Level();


	bool isClicked() override;
	void render() const override;
private:
	//Texture2D locker;
};

class LevelsScreen final : public EventHandler {
public:
	Color backgroundColor;

	LevelsScreen();
	~LevelsScreen();

	void process();
private:
	const int screenWidth = GetScreenWidth();
	const int screenHeight = GetScreenHeight();
	std::vector<Level> levels;
};