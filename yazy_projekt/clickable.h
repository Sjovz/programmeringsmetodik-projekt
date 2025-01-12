#ifndef CLICKABLE_H
#define CLICKABLE_H
#include "raylib.h"
#include <functional>

class Game;
class Drawable {
// add sprites to this soon 

public:
    Drawable(Rectangle rect);
    virtual void update() {} // Default update does nothing
    virtual void draw(); 

    void setColor(Color newColor) {
        color = newColor;
    }

protected:
    Rectangle rect;
    Color color = {0, 0, 0, 255};
};

class Clickable : public Drawable {
public:
    Clickable(Rectangle rect, std::function<void()> onClick, Game* owner);  
    void remove();  
    void update() override;

private:
    std::function<void()> onClick;
    Game* owner;
};
#endif // !CLICKABLE_H
