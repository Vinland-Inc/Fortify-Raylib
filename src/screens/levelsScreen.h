#pragma once
#include "raylib.h"
#include "../Extensions.h"
#include "../eventhandler/EventHandler.h"
#include "../levels/LevelData.h"

#define LEVEL_BUTTON_WIDTH 400
#define LEVEL_BUTTON_HEIGHT 200

class Level final : public extensions::Button { //final значит, что нельзя наследоваться от этого класса дальше
public: 
	LevelConfig config;
	bool isClosed;

	Level();
	~Level();
	

	bool isClicked() override;
	void render() const override;
    void setLocker(Texture2D *lockerPtr);
    
	
  private:
	Texture2D* locker;
};

class LevelsScreen final : public EventHandler {
public:
	Color backgroundColor;

	LevelsScreen();
	~LevelsScreen();

	void activate();
	void process();
private:
    int lastCompletedLevel = 1;
    int loadLastCompletedLevel() const;
	const int screenWidth = GetScreenWidth();
	const int screenHeight = GetScreenHeight();
	std::vector<Level> levels;
    Texture2D sharedLocker;
};
