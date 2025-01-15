/************************************************************************************
 * File Name: clickable.h
 * Author: Erik Sawander
 * Date: 2025-01-15
 * Version: 2.0
 *
 * this file contains the drawable and clickable object, as well as a factory class for producing them for usage in the game class
 * drawable object allows itself to be drawn to screen
 * clickable object allows itself to be clicked, requires a delegate to handle its on click behaviour
 ************************************************************************************/

#ifndef CLICKABLE_H
#define CLICKABLE_H
#include "event_handler.h"
#include "raylib.h"
#include <functional>

class Event_handler;
class Game;

// NOTE: Drawable and its children should allways have private constructors
// this is to obscure them entirely from the user
// a factory class should be used to construct these objects and make sure the pointers are handled appropriately
class Drawable {
friend class click_engine;
friend class Drawable; 
// add sprites to this 
public: 
    int get_id();
    // Default update does nothing
    virtual void update() {} 
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
    // not ownership
    Event_handler* handler;
    Texture2D texture;
    bool has_texture;
};

class Clickable : public Drawable {
friend class click_engine;
friend class Drawable; 
public: 
    // allows an outside class to call the update method in order for it to poll the game once for a click 
    void update() override;
protected:
    Clickable(Rectangle rect, std::function<void()> onClick, Event_handler* handler, int id);  
    Clickable(Rectangle rect, std::function<void()> onClick, Event_handler* handler, int id, Texture2D texture);  
    std::function<void()> onClick;
};

class click_engine {
public: 
    // these all call the appropriate constructor and subscribes to the drawable manager contained in game
    static void make_clickable(Rectangle rect, std::function<void()> onClick, Game& owner, int id);
    static void make_clickable(Rectangle rect, std::function<void()> onClick, Game& owner, int id, Texture2D texture);
    static void make_drawable(Rectangle rect, int id, Game& game);
    static void make_drawable(Rectangle rect, int id, Game& game, Texture2D texture);
};
#endif // !CLICKABLE_H
