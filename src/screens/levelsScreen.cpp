#include "levelsScreen.h"

LevelsScreen::LevelsScreen() : EventHandler(), backgroundColor(BLACK)
{
	const int HORIZONTAL_GAP = 20, VERTICAL_GAP = 200;
	int row = 0, column = 0;
	for (int i = 0; i < 8; ++i) { // Начинаем с 0
		column = i % 4; // 0, 1, 2, 3, 0, 1, 2, 3
		row = i / 4;    // 0, 0, 0, 0, 1, 1, 1, 1

		Level level;
		level.levelNumber = i + 1;
		level.name = "Dangerous dungeon";
		level.texture = LoadTexture("sprites/map/spritesheet.png");
		float x = float(screenWidth / 2) - 840 + column * (LEVEL_BUTTON_WIDTH + HORIZONTAL_GAP); //тут высчитал, почему 840
		float y = float(screenHeight / 2) - 330 + row * (LEVEL_BUTTON_HEIGHT + VERTICAL_GAP); //тут наугад сука почему-то не 300, а 340, потом подумаю
		level.rect = { x, y, LEVEL_BUTTON_WIDTH, LEVEL_BUTTON_HEIGHT };
		level.isClosed = i >= 1; //пока те уровни, что больше или равны 1, недоступны нахуй, потом это все откуда-то читать надо

		levels.push_back(level); //можно пофиксить трабл с замком, сделав вектор хранящим не обьекты, а указатель на обьекты Level, но это в крайнем случае
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

LevelsScreen::~LevelsScreen() {}

Level::Level() : extensions::Button(), isClosed(true), levelNumber(0)
{ 
	//locker = LoadTexture("sprites/UI/level-locker.png");
}

bool Level::isClicked()
{
	bool isClicked = !isClosed && isHovered && IsMouseButtonReleased(MOUSE_BUTTON_LEFT); //если уровень доступен, наведен и ебанная левая кнопка мыши отжата, значит по нему нажали все-таки
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

	//хуйня с этой текстурой связана с добавлением в вектор, там создается копия, этот экземпляр удаляется - очищается текстура, в векторе копия указывает на мусорную хуету, как я понял
	//if (isClosed) {
	//	DrawTexturePro(
	//		locker,
	//		Rectangle{ 0, 0, float(locker.width), float(locker.height) },
	//		Rectangle({ rect.x + (rect.width - 30) / 2, rect.y + (rect.height + 100 - 40) / 2, 30, 40 }),
	//		Vector2{ 0, 0 },
	//		0,
	//		WHITE
	//	);
	//}

	DrawText(
		name.c_str(), //чтобы из string в const char*
		rect.x + 10, 
		rect.y + texture.height + 50, 
		24, 
		isClosed ? GRAY : WHITE
	);

	extensions::DrawRectangleLinesEx(rect, thickness, WHITE);
}

Level::~Level()
{
	//UnloadTexture(locker);
	//texture разгружается в деструкторе BUTTON
}
