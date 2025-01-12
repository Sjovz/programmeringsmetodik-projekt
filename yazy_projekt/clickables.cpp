#include "clickable.h"
#include"game.h"

Drawable::Drawable(Rectangle rect) : rect(rect) {}

void Drawable::draw()
{
    DrawRectangleRec(rect, color);
}

Clickable::Clickable(Rectangle rect, std::function<void()> onClick, Game* owner)
        : Drawable(rect), onClick(onClick), owner(owner) {owner->add_clickable(this);}

void Clickable::remove() {owner->remove_clickable(this);}

void Clickable::update() {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
        CheckCollisionPointRec(GetMousePosition(), rect)) {
        owner->add_action(onClick);
    }
}
