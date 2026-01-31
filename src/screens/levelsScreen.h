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
    void setLocker(Texture2D *lockerPtr);
	
	// вот эти 2 переменные и те что в прайват которые закоммичены наверно надо вынести в какуюто структуру по типу
    // LevelsConfig, и наверно надо чтобы GameScreen мог их читать, чтобы брать например количество и тип врагов для
    // спавна на уровне, карту, название, и дохуя чего чего еще
    // Texture2D getLevelTexture(int level);
    // std::string getLevelName(int level);
  private:
    //Texture2D levelTextures[8];
	//std::string levelNames[8];
	Texture2D* locker;
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
    Texture2D sharedLocker;
};
