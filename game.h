/************************************************************************************
 * File Name: game.h
 * Author: Erik Sawander
 * Date: 2025-01-12
 * Version: 1.0
 *
 * implements the IO part of the game 
 * philosophy was to make a game not a game engine 
 * simple and event driven, and the only event type is clicking on things
 * 
 ************************************************************************************/
#ifndef GAME_H
#define GAME_H

#include "clickable.h"
#include <functional>
#include <vector>

// right now this is both the event listener and the game itself, might want to split responsibilities 
// figure out what should be public and private in all of the classes actually 
class Game {
public:
    Game();
    void add_drawable(Drawable* drawable); 
    void remove_drawable(Drawable* drawable); 
    void remove_drawable(int id);
    void remove_drawables();
    void add_action(std::function<void()> action);
    void process_actions(); 
    void loop();
private:
    void init();
    std::vector<std::function<void()>> deffered_actions;
    // make this more polymorphy 
    std::vector<Drawable*> drawables;
    std::vector<Drawable*> drawables_to_remove;
    // add a destructor 
};
#endif 
