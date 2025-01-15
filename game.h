/************************************************************************************
 * File Name: game.h
 * Author: Erik Sawander
 * Date: 2025-01-15
 * Version: 2.0
 *
 * Implements a basic game engine design 
 * strictly event based, and in this the only event is clicking on clickables 
 * note that this is tightly coupled with the factory class click_engine, does nothing without it 
 ************************************************************************************/
#ifndef GAME_H
#define GAME_H
#include "drawable_manager.h"
class Game {
friend class click_engine;
public:
    Game();
    // removes a drawable object by id
    void remove_drawable(int id);
    // adds a drawable object by it's pointer (depreciated behaviour) 
    void remove_drawable(Drawable* drawable); 
    // starts the games loop
    void loop();
private:
    Drawable_manager drawable_manager;
    Event_handler event_handler;
    void init();
    // add a destructor 
};

#endif 
