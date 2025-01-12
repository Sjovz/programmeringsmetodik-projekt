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

// this is a fucking event listener with way too many responsibilities 
class Game {
public:
    Game();
    void add_clickable(Clickable* clicker); 
    void remove_clickable(Clickable* clicker); 
    void remove_clickables();
    void add_action(std::function<void()> action);
    void process_actions(); 
private:
    void init();
    void loop();
    std::vector<std::function<void()>> deffered_actions;
    // make this more polymorphy 
    std::vector<Clickable*> clickables_to_remove;
    std::vector<Clickable*> clickables;
    // add a destructor 
};

#endif 
