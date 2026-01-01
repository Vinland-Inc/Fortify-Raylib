#pragma once
#include <iostream>
#include "raylib.h"

class SoundPlayer {
public:
	SoundPlayer();
	~SoundPlayer();
	bool load(std::string soundPath);
	void setVolume(float volume);
	void play();
	void unload();
private:
	Sound sound;
	bool isLoaded;
	float volume;
};
