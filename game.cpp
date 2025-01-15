#include "game.h"
<<<<<<< HEAD
#include "clickable.h"
#include "raylib.h"
#include "yazygame.h"
#include <iostream>
=======
>>>>>>> 2ecd9c2b9637d0a32745339fb181560a1d78bb8b

Game::Game()
{
    init();
}

void Game::init()
{
    InitWindow(960, 540, "Yazy Game :)");
    SetTargetFPS(60);
}


void Game::remove_drawable(int id)
{
    drawable_manager.remove_drawable(id);
}


void Game::remove_drawable(Drawable* drawable) 
{
    drawable_manager.remove_drawable(drawable);
}

void Game::loop()
{
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE); 
        for(auto drawable : drawable_manager)        
        {
            drawable->draw();
        }
        EndDrawing();
        for(auto drawable: drawable_manager)        
        {
            drawable->update();
        }
        event_handler.process_actions();
        drawable_manager.remove_drawables();
    }
}
