#pragma once
#include "raylib.h"
#include "audio/SoundPlayer.h"

#define DEFAULT_BUTTON_COLOR WHITE //вот это и снизу мне кажется зря, потому что кнопок будет десятки, те цвета что я выбрал вроде подходят для меню, но точно не везде
#define HOVERED_BUTTON_COLOR YELLOW

namespace extensions {

	class Button {
	public:
		Button();
		~Button();

		void hover(); //функция, что будет менять цвет, если мышка наведена
		bool isClicked(); //будем проверять тут, нажата ли кнопка
		void render() const;

		void setClickSound(SoundPlayer* sound);

		Color color = DEFAULT_BUTTON_COLOR;
		Texture2D texture;
		Rectangle rect;
	private:
		bool isHovered; //тут будем хранить, наведена ли в текущий кадр кнопка или нет, чтобы кучу функций проверки не вызывать, онли в hover

		SoundPlayer* sound = nullptr; //будем хранить указатель на SoundPlayer из Menu, это меньше памяти
	};
}
