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
#include "drawable_manager.h"
class Game {
friend class click_engine;
public:
    Game();
    void remove_drawable(int id);
    void remove_drawable(Drawable* drawable); 
    void loop();
private:
    Drawable_manager drawable_manager;
    Event_handler event_handler;
    void init();
    // add a destructor 
};

#endif 
