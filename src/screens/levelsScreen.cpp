#include <fstream>
#include "levelsScreen.h"

LevelsScreen::LevelsScreen() : EventHandler(), backgroundColor(BLACK)
{
    sharedLocker = LoadTexture("sprites/UI/level-locker.png");
    sharedLocker.height *= 3;
    sharedLocker.width *= 3;

	lastCompletedLevel = loadLastCompletedLevel();

	const int HORIZONTAL_GAP = 20, VERTICAL_GAP = 200;
	int row = 0, column = 0;
	for (int i = 0; i < 8; ++i) { // Начинаем с 0
		column = i % 4; // 0, 1, 2, 3, 0, 1, 2, 3
		row = i / 4;    // 0, 0, 0, 0, 1, 1, 1, 1

		Level level;
		level.levelNumber = i + 1;
		level.name = "Dangerous dungeon";
		level.texture = LoadTexture("sprites/map/spritesheet.png");
        level.setLocker(&sharedLocker);
		float x = float(screenWidth / 2) - 840 + column * (LEVEL_BUTTON_WIDTH + HORIZONTAL_GAP);
		float y = float(screenHeight / 2) - 330 + row * (LEVEL_BUTTON_HEIGHT + VERTICAL_GAP); 
		level.rect = { x, y, LEVEL_BUTTON_WIDTH, LEVEL_BUTTON_HEIGHT };
        level.isClosed = i >= lastCompletedLevel; 
		levels.push_back(level);
	}
}

void LevelsScreen::process()
{
	for (auto& level : levels) {
		level.hover();

		if (level.isClicked())
			emit("level_clicked", level.levelNumber);
		
		level.render();
	}
}

int LevelsScreen::loadLastCompletedLevel() const
{
    std::fstream file("src/.last_completed_level.txt");
    if (!file.is_open())
    {
        std::cerr << "Couldn't open the file for reading\n";
        return 1;
    }
    
	int value;
    file >> value;
    return value;
}

LevelsScreen::~LevelsScreen()
{
    UnloadTexture(sharedLocker);
}

Level::Level() : extensions::Button(), isClosed(true), levelNumber(0)
{ 
}

bool Level::isClicked()
{
	bool isClicked = !isClosed && isHovered && IsMouseButtonReleased(MOUSE_BUTTON_LEFT);
	if (isClicked && sound)
		sound->play();

	return isClicked;
}

void Level::render() const
{
	float thickness = isHovered && !isClosed ? 3.f : 1.f;

	DrawTexturePro(
		texture, 
		Rectangle{ 0, 0, (float)texture.width, (float)texture.height }, 
		rect, 
		{ 0, 0 }, 
		0, 
		isClosed ? GRAY : WHITE
	);

	if (isClosed && locker) {
		DrawTexturePro(
			*locker,
			Rectangle{ 0, 0, float(locker->width), float(locker->height) },
			Rectangle({ 
				rect.x + (rect.width - (float)locker->width) / 2, 
				rect.y + (rect.height + 70 - (float)locker->height) / 2, 
				(float)locker->width, 
				(float)locker->height }),
			Vector2{ 0, 0 },
			0,
			WHITE
		);
	}

	DrawText(
		name.c_str(), //чтобы из string в const char*
		rect.x + 10, 
		rect.y + texture.height + 50, 
		24, 
		isClosed ? GRAY : WHITE
	);

	extensions::DrawRectangleLinesEx(rect, thickness, WHITE);
}

void Level::setLocker(Texture2D* lockerPtr)
{
    locker = lockerPtr;
}

Level::~Level()
{
}
