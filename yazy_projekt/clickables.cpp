#include "clickable.h"
#include "game.h"
#include "raylib.h"

Drawable::Drawable(Rectangle rect, int id, Game* game) : rect(rect), id(id), owner(game), has_texture(false)
{
    owner->add_drawable(this); 
}
// TODO:
Drawable::Drawable(Rectangle rect, int id, Game* game, Texture2D texture) : rect(rect), id(id), owner(game), has_texture(true), texture(texture) 
{
    owner->add_drawable(this); 
}

int::Drawable::get_id() {return id;}

void::Drawable::draw()
{
    Rectangle sourceRect = { 0, 0, (float)texture.width, (float)texture.height };
    if (has_texture)
    DrawTexturePro(
                    texture,
                    sourceRect,
                    rect,      // Using rect directly as destination rectangle
                    {0, 0},    // Origin point (0,0 for top-left)
                    0.0f,      // Rotation (in degrees)
                    WHITE
                );
    else 
        DrawRectangleRec(rect, color);
}

Clickable::Clickable(Rectangle rect, std::function<void()> onClick, Game* owner, int id) : Drawable(rect, id, owner), onClick(onClick) {}
Clickable::Clickable(Rectangle rect, std::function<void()> onClick, Game* owner, int id, Texture2D texture) : Drawable(rect, id, owner, texture), onClick(onClick) {}

void::Clickable::remove() { owner->remove_drawable(this); }

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
void click_engine::make_drawable(Rectangle rect, int id, Game* game, Texture2D texture)
{
    new Drawable(rect ,id, game, texture);
}
void click_engine::make_clickable(Rectangle rect, std::function<void()> onClick, Game* owner, int id, Texture2D texture)
{
    new Clickable(rect, onClick, owner, id, texture);
}
