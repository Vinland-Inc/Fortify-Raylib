#include "Extensions.h"

extensions::Button::Button() {}

void extensions::Button::hover()
{
    isHovered = CheckCollisionPointRec(GetMousePosition(), rect);
    
    color = isHovered ? HOVERED_BUTTON_COLOR : DEFAULT_BUTTON_COLOR;
}

bool extensions::Button::isClicked()
{
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        color = DEFAULT_BUTTON_COLOR;
    }

    bool isClicked = isHovered && IsMouseButtonReleased(MOUSE_BUTTON_LEFT);
    if (isClicked && sound)
        sound->play();

    return isClicked; //если наведена и нажата, то true
}

void extensions::Button::render() const
{
    DrawTexturePro(texture, Rectangle{ 0, 0, (float)texture.width, (float)texture.height }, rect, Vector2{ 0, 0 }, 0.0f, color);
}

void extensions::Button::setClickSound(SoundPlayer* sound)
{
    this->sound = sound;
}

extensions::Button::~Button()
{
    UnloadTexture(texture);
}
