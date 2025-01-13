#include "clickable.h"
#include"game.h"

::Drawable::Drawable(Rectangle rect, int id, Game* game) : rect(rect), id(id), owner(game) {owner->add_drawable(this);}

int::Drawable::get_id() {return id;}
void::Drawable::draw()
{
    DrawRectangleRec(rect, color);
}

Clickable::Clickable(Rectangle rect, std::function<void()> onClick, Game* owner, int id)
    : Drawable(rect, id, owner), onClick(onClick) {}

void::Clickable::remove() {owner->remove_drawable(this);}

// maybe something else should be distrubuting the mouse position? kind of inneficient 
void Clickable::update() {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
        CheckCollisionPointRec(GetMousePosition(), rect)) {
        owner->add_action(onClick);
    }
}

void click_engine::make_drawable(Rectangle rect, int id, Game* game)
{
    new Drawable(rect ,id, game);
}
void click_engine::make_clickable(Rectangle rect, std::function<void()> onClick, Game* owner, int id)
{
    new Clickable(rect, onClick, owner, id);
}
