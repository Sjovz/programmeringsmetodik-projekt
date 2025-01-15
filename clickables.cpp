#include "clickable.h"
#include "game.h"
#include "event_handler.h"

Drawable::Drawable(Rectangle rect, int id, Event_handler* handler) : rect(rect), id(id), handler(handler), has_texture(false)
{}

Drawable::Drawable(Rectangle rect, int id, Event_handler* handler, Texture2D texture) : rect(rect), id(id), handler(handler), has_texture(true), texture(texture) 
{}

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

Clickable::Clickable(Rectangle rect, std::function<void()> onClick, Event_handler* handler, int id) : Drawable(rect, id, handler), onClick(onClick) {}
Clickable::Clickable(Rectangle rect, std::function<void()> onClick, Event_handler* handler, int id, Texture2D texture) : Drawable(rect, id, handler, texture), onClick(onClick) {}

// maybe something else should be distrubuting the mouse position? kind of inneficient 
void Clickable::update() {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
        CheckCollisionPointRec(GetMousePosition(), rect)) {
        handler->add_action(onClick);
    }
}

void click_engine::make_drawable(Rectangle rect, int id, Game& game)
{
    Drawable* drawable = new Drawable(rect ,id, &game.event_handler);
    game.drawable_manager.add_drawable(drawable);
}
void click_engine::make_clickable(Rectangle rect, std::function<void()> onClick, Game& owner, int id)
{
    Clickable* drawable = new Clickable(rect, onClick, &owner.event_handler, id);
    owner.drawable_manager.add_drawable(drawable);
}
void click_engine::make_drawable(Rectangle rect, int id, Game& game, Texture2D texture)
{
    Drawable* drawable = new Drawable(rect ,id, &game.event_handler, texture);
    game.drawable_manager.add_drawable(drawable);
}
void click_engine::make_clickable(Rectangle rect, std::function<void()> onClick, Game& owner, int id, Texture2D texture)
{
    Clickable* drawable = new Clickable(rect, onClick, &owner.event_handler, id, texture);
    owner.drawable_manager.add_drawable(drawable);
}
