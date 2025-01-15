#include "clickable.h"
#include "game.h"
#include "event_handler.h"

Drawable::Drawable(Rectangle rect, int id, Event_handler* handler) : rect(rect), id(id), handler(handler), has_texture(false), has_text(false)
{}

Drawable::Drawable(Rectangle rect, int id, Event_handler* handler, Texture2D texture) : rect(rect), id(id), handler(handler), has_texture(true), texture(texture), has_text(false)
{}

Drawable::Drawable(Rectangle rect, int id, Event_handler* handler, std::string text, float font_size) : rect(rect), id(id), handler(handler), has_texture(false), has_text(true), text(text), font_size(font_size)
{}

int::Drawable::get_id() {return id;}

void::Drawable::draw()
{
    Rectangle sourceRect = { 0, 0, (float)texture.width, (float)texture.height };
    if (has_texture)
    DrawTexturePro(
                    texture,
                    sourceRect,
                    rect,      
                    {0, 0},   
                    0.0f,    
                    WHITE
                );
    else if (has_text)
         DrawTextEx(GetFontDefault(), text.c_str(), {rect.x, rect.y}, 20.0f , 1.0f, color);
    else 
    DrawRectangleRec(rect, color);
}

Clickable::Clickable(Rectangle rect, std::function<void()> onClick, Event_handler* handler, int id) : Drawable(rect, id, handler), onClick(onClick) {}
Clickable::Clickable(Rectangle rect, std::function<void()> onClick, Event_handler* handler, int id, Texture2D texture) : Drawable(rect, id, handler, texture), onClick(onClick) {}
Clickable::Clickable(Rectangle rect, std::function<void()> onClick, Event_handler* handler, int id, std::string text, float font_size) : Drawable(rect, id, handler, text, font_size), onClick(onClick) {}

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
void click_engine::make_clickable(Rectangle rect, std::function<void()> onClick, Game& owner, int id, std::string text, float font_size)
{
    Clickable* drawable = new Clickable(rect, onClick, &owner.event_handler, id, text, font_size);
    owner.drawable_manager.add_drawable(drawable);
}
void click_engine::make_drawable(Rectangle rect, int id, Game& game, std::string text, float font_size)
{
    Drawable* drawable = new Drawable(rect ,id, &game.event_handler, text, font_size);
    game.drawable_manager.add_drawable(drawable);
}
