#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "clickable.h"
#include "raylib.h"
#include "yazygame.h"
#include "game.h"
#include <random>

// all we need to do now is add sprites, animations and set up another layer of abstraction to get the yatzee class to interact the new graphics/click handling class 
// if we have time we can split the responsibilities better in the game class so that it isnt both the event listener and the game at the same time.
// and also maybe add an abstract class for the command handling so that its not all gross lamda captures :) 


// stupid demo game made by ai
class ClickGame {
private:
    Game& game;
    std::mt19937 rng;
    std::uniform_int_distribution<int> x_dist;
    std::uniform_int_distribution<int> y_dist;
    const float BOX_WIDTH = 50.0f;
    const float BOX_HEIGHT = 50.0f;
    int score = 0;
    int game_id = 0;
    Texture2D texture;
    
    // Keep track of the "reset" button
    Rectangle reset_button;
    int reset_button_id;

public:
    ClickGame(Game& g, int screen_width = 800, int screen_height = 600) 
        : game(g), 
          rng(std::random_device{}()),
          x_dist(0, screen_width - static_cast<int>(50.0f)),
          y_dist(0, screen_height - static_cast<int>(50.0f)) {
        
        // Create persistent reset button at top of screen
        reset_button = Rectangle{10.0f, 10.0f, 100.0f, 30.0f};
        reset_button_id = game_id;
        game_id++;
        texture = LoadTexture("Unknown.jpeg");
        
        click_engine::make_clickable(reset_button, 
            [this]() {
                reset_game();
            }, 
            &game, 
            reset_button_id
        );

        // Spawn initial box
        spawn_box();
    }

private:
    void spawn_box() {
        float x = static_cast<float>(x_dist(rng));
        float y = static_cast<float>(y_dist(rng));
        
        Rectangle new_box{x, y, BOX_WIDTH, BOX_HEIGHT};
        
        // Generate unique ID for the box
        int id = game_id;
        game_id++;

        // When box is clicked:
        // 1. Remove this box
        // 2. Increment score
        // 3. Spawn a new box
        click_engine::make_clickable(new_box, 
            [this, id]() {
                game.remove_drawable(id);
                score++;
                std::cout << "Score: " << score << std::endl;
                spawn_box();  // Spawn next box immediately
            }, 
            &game, 
            id,
            texture
        );
    }

    void reset_game() {
        score = 0;
        std::cout << "Game Reset! Score: 0" << std::endl;
        // Could add additional reset logic here if needed
    }
};

int main() 
{
    Game game;
    ClickGame click_game(game);
    game.loop();
    return 0;
}
