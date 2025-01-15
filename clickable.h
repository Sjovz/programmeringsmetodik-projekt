#ifndef CLICKABLE_H
#define CLICKABLE_H
#include "event_handler.h"
#include "raylib.h"
#include <functional>

class Event_handler;
class Game;

class Drawable {
friend class click_engine;
friend class Drawable; 
// add sprites to this 
public: 
    int get_id();
    virtual void update() {} // Default update does nothing
    virtual void draw(); 
protected:
    Drawable(Rectangle rect, int id, Event_handler* handler);
    Drawable(Rectangle rect, int id, Event_handler* handler, Texture2D texture);
    
    void setColor(Color newColor) {
        color = newColor;
    }
    int id; 
    Rectangle rect;
    Color color = {0, 0, 0, 255};
    Event_handler* handler;
    Texture2D texture;
    bool has_texture;
};

class Clickable : public Drawable {
friend class click_engine;
friend class Drawable; 
public: 
    void update() override;
protected:
    Clickable(Rectangle rect, std::function<void()> onClick, Event_handler* handler, int id);  
    Clickable(Rectangle rect, std::function<void()> onClick, Event_handler* handler, int id, Texture2D texture);  
    std::function<void()> onClick;
};

class click_engine {
public: 
    static void make_clickable(Rectangle rect, std::function<void()> onClick, Game& owner, int id);
    static void make_clickable(Rectangle rect, std::function<void()> onClick, Game& owner, int id, Texture2D texture);
    static void make_drawable(Rectangle rect, int id, Game& game);
    static void make_drawable(Rectangle rect, int id, Game& game, Texture2D texture);
};
#endif // !CLICKABLE_H
