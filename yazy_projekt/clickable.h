#ifndef CLICKABLE_H
#define CLICKABLE_H
#include "raylib.h"
#include <functional>

class Game;
class Drawable {
// add sprites to this 
friend class Game;
friend class click_engine;
protected:
    Drawable(Rectangle rect, int id, Game* owner);
    Drawable(Rectangle rect, int id, Game* owner, Texture2D texture);
    virtual void update() {} // Default update does nothing
    virtual void draw(); 
    int get_id();
    
    void setColor(Color newColor) {
        color = newColor;
    }
    int id; 
    Rectangle rect;
    Color color = {0, 0, 0, 255};
    Game* owner;
    Texture2D texture;
    bool has_texture;
};

class Clickable : public Drawable {
friend class Game;
friend class click_engine;
protected:
    Clickable(Rectangle rect, std::function<void()> onClick, Game* owner, int id);  
    Clickable(Rectangle rect, std::function<void()> onClick, Game* owner, int id, Texture2D texture);  
    void remove();  
    void update() override;
    std::function<void()> onClick;
};

class click_engine {
public: 
    static void make_clickable(Rectangle rect, std::function<void()> onClick, Game* owner, int id);
    static void make_clickable(Rectangle rect, std::function<void()> onClick, Game* owner, int id, Texture2D texture);
    static void make_drawable(Rectangle rect, int id, Game* game);
    static void make_drawable(Rectangle rect, int id, Game* game, Texture2D texture);
};
#endif // !CLICKABLE_H
