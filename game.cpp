#include "game.h"
#include "clickable.h"
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
}

void Game::add_drawable(Drawable* drawable){drawables.push_back(drawable);}

void Game::remove_drawable(int id)
{
    auto it = std::find_if(drawables.begin(), drawables.end(), [id](const auto & drawable){return drawable->get_id() == id;});
    if (it != drawables.end()) {
       drawables_to_remove.push_back(*it);
       drawables.erase(it);
    }
}

void Game::remove_drawable(Drawable* drawable) {
    auto it = std::find(drawables.begin(), drawables.end(), drawable);
    if (it != drawables.end()) {
       drawables.erase(it);
    }
    drawables_to_remove.push_back(drawable);
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

void Game::remove_drawables()
{
    for (Drawable* drawable: drawables_to_remove) 
        delete drawable;  
    drawables_to_remove.clear();
}

void Game::loop()
{
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE); 
        for(auto drawable: drawables)        
        {
            drawable->draw();
        }
        EndDrawing();
        for(auto drawable: drawables)        
        {
            drawable->update();
        }
        process_actions();
        remove_drawables();
    }
}
