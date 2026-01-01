#include "SoundPlayer.h"

SoundPlayer::SoundPlayer()
{
	volume = 1.f;
	isLoaded = false;
	sound = { 0 };
}

bool SoundPlayer::load(std::string soundPath)
{
	if (isLoaded) {
		unload();
	}

	if (!IsAudioDeviceReady()) {
		std::cerr << "Audio device is not ready\n";
		return false;
	}

	sound = LoadSound(soundPath.c_str()); //почему-то не воспринимает просто string, переносим в строку из СИ

	if (sound.frameCount == 0) {
		std::cerr << "ERROR: sound was not loaded\n";
		return false;
	}

	isLoaded = true;
	SetSoundVolume(sound, volume);
}

void SoundPlayer::setVolume(float volume)
{
	this->volume = volume < 0.f ? 0.f : volume > 1.f ? 1.f : volume; //если меньше 0, то 0, если больше 1, то 1, иначе то, что поставил
}

void SoundPlayer::play()
{
	if (isLoaded) {
		PlaySound(sound);
	}
	else {
		std::cerr << "ERROR: sound is not loaded\n";
	}
}

void SoundPlayer::unload()
{
	if (!isLoaded)
	{
		std::cerr << "ERROR: No sound is loaded\n";
	}

	UnloadSound(sound);
}

SoundPlayer::~SoundPlayer()
{
	unload();
}
