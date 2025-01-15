#include "game.h"

Game::Game()
{
    init();
}

void Game::init()
{
    InitWindow(800, 600, "game");
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
