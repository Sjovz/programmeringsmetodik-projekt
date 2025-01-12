#include "game.h"
#include "raylib.h"
#include "yazygame.h"
#include <iostream>


Game::Game()
{
    init();
}

void Game::init()
{
    InitWindow(800, 600, "game");
    SetTargetFPS(60);
    yazygame test;
    Rectangle rect{20, 20, 100, 50};
    Clickable bob(rect, [](){}, this);
    loop();
}

void Game::add_clickable(Clickable* clicker){clickables.push_back(clicker);}

void Game::remove_clickable(Clickable* clicker) {
    auto it = std::find(clickables.begin(), clickables.end(), clicker);
    if (it != clickables.end()) {
       clickables.erase(it);  // Remove the element from clickables
    }
    clickables_to_remove.push_back(clicker);
}

void Game::process_actions() 
{
    for (auto& action : deffered_actions) {
        action();
    }
    deffered_actions.clear();
}

void Game::add_action(std::function<void()> action) 
{
    deffered_actions.push_back(action);
}

void Game::remove_clickables()
{
    for (Clickable* clickable : clickables_to_remove) 
        delete clickable;  // Delete each Clickable object
    clickables_to_remove.clear();
}

void Game::loop()
{
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE); 
        for(auto clicker: clickables)        
        {
            clicker->draw();
        }
        EndDrawing();
        for(auto clicker: clickables)        
        {
            clicker->update();
        }
        process_actions();
        remove_clickables();
    }
}
