#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>
#include "clickable.h"
#include "raylib.h"
#include "yazyfunct.h"
#include "game.h"
/*
class YazyGame {
private:
    Game& game;
    yazyfunct logic; // Core game logic class
    const int DICE_COUNT = 5;

    // UI elements
    Rectangle reset_button;
    Rectangle roll_button;
    Rectangle reroll_button;

    int reset_button_id = 0;
    int roll_button_id = 1;
    int reroll_button_id = 2;

    int dice_id[6] = {3, 4, 5, 6, 7, 8};

    // Flags for dice to reroll
    bool reroll_flags[5] = {false, false, false, false, false};

    // Dice textures
    Texture2D dice_textures[6];

    void reset_game() {
        logic = yazyfunct(); // Reset the logic object
        for (bool& reroll_flag : reroll_flags) {
            reroll_flag = false;
        }
        std::cout << "Game reset!" << std::endl;
    }

    void roll_all_dice() {
        logic.rollAllDice();
        std::cout << "Rolled all dice!" << std::endl;
    }

    void reroll_selected_dice() {
        logic.rerollDice(reroll_flags);
        for (bool& reroll_flag : reroll_flags) {
            reroll_flag = false; // Reset reroll flags
        }
        std::cout << "Rerolled selected dice!" << std::endl;
    }

    void toggle_reroll_flag(int index) {
        reroll_flags[index] = !reroll_flags[index];
        std::cout << "Toggled reroll for die " << index + 1 << ": " << (reroll_flags[index] ? "ON" : "OFF") << std::endl;
    }

public:
    YazyGame(Game& game) : game(game) {
        // Initialize buttons
        reset_button = {10.0f, 10.0f, 100.0f, 50.0f};
        roll_button = {300.0f, 500.0f, 200.0f, 50.0f};
        reroll_button = {300.0f, 560.0f, 200.0f, 50.0f};

        // Load dice textures
        for (int i = 0; i < 6; ++i) {
            std::string path = "C:/Users/Ellev/CLionProjects/yazy/Data/dice" + std::to_string(i + 1) + ".png";
            dice_textures[i] = LoadTexture(path.c_str());
        }

        // Set up clickable buttons
        click_engine::make_clickable(reset_button, [this]() { reset_game(); }, game, reset_button_id);
        click_engine::make_clickable(roll_button, [this]() { roll_all_dice(); }, game, roll_button_id);
        click_engine::make_clickable(reroll_button, [this]() { reroll_selected_dice(); }, game, reroll_button_id);

        // Make dice toggleable for rerolling
        float dice_x_start = 250.0f;
        for (int i = 0; i < DICE_COUNT; ++i) {
            Rectangle die_area = {dice_x_start + i * 70.0f, 400.0f, 50.0f, 50.0f};
            click_engine::make_clickable(die_area, [this, i]() { toggle_reroll_flag(i); }, game, dice_id[i]);
        }
    }

    ~YazyGame() {
        for (int i = 0; i < 6; ++i) {
            UnloadTexture(dice_textures[i]);
        }
    }

    void draw() {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw reset button
        DrawRectangleRec(reset_button, RED);
        DrawText("Reset", reset_button.x + 10.0f, reset_button.y + 10.0f, 20, WHITE);

        // Draw roll button
        DrawRectangleRec(roll_button, GREEN);
        DrawText("Roll All", roll_button.x + 10.0f, roll_button.y + 10.0f, 20, WHITE);

        // Draw reroll button
        DrawRectangleRec(reroll_button, BLUE);
        DrawText("Roll Selected", reroll_button.x + 10.0f, reroll_button.y + 10.0f, 20, WHITE);

        // Draw dice and indicate reroll flags
        float dice_x_start = 250.0f;
        for (int i = 0; i < DICE_COUNT; ++i) {
            int dice_value = logic.getDiceValue(i) - 1; // Get the dice value
            DrawTexture(dice_textures[dice_value], dice_x_start + i * 70.0f, 400.0f, WHITE);

            // Indicate reroll status with a border
            if (reroll_flags[i]) {
                DrawRectangleLinesEx({dice_x_start + i * 70.0f, 400.0f, 50.0f, 50.0f}, 2, RED);
            }
        }

        // Example: Draw score for ones
        int ones_score = logic.same_number(1, logic.getDiceArray());
        DrawText(("Score for Ones: " + std::to_string(ones_score)).c_str(), 10, 100, 20, BLACK);

        EndDrawing();
    }
};*/

class YazyGame {
    private:
    Game& game;
    yazyfunct logic;

    std::vector<bool> reroll_flags = {true, true, true, true, true};

    Rectangle roll_all_button = {400, 200, 50, 20};
    Rectangle roll_some_button = {200, 200, 50, 20};

    Rectangle dice1_button = {100, 500, 50, 50};
    Rectangle dice2_button = {200, 500, 50, 50};
    Rectangle dice3_button = {300, 500, 50, 50};
    Rectangle dice4_button = {400, 500, 50, 50};
    Rectangle dice5_button = {500, 500, 50, 50};

    const int roll_all_button_id = 0;
    const int roll_some_button_id = 1;

    const int dice1_button_id = 2;
    const int dice2_button_id = 3;
    const int dice3_button_id = 4;
    const int dice4_button_id = 5;
    const int dice5_button_id = 6;

    Texture2D dice1_texture = LoadTexture("C:/Users/Ellev/ClionProjects/yazy/Data/dice1.png");
    Texture2D dice2_texture = LoadTexture("C:/Users/Ellev/ClionProjects/yazy/Data/dice2.png");
    Texture2D dice3_texture = LoadTexture("C:/Users/Ellev/ClionProjects/yazy/Data/dice3.png");
    Texture2D dice4_texture = LoadTexture("C:/Users/Ellev/ClionProjects/yazy/Data/dice4.png");
    Texture2D dice5_texture = LoadTexture("C:/Users/Ellev/ClionProjects/yazy/Data/dice5.png");
    Texture2D dice6_texture = LoadTexture("C:/Users/Ellev/ClionProjects/yazy/Data/dice6.png");


    public:
    YazyGame(Game& game) : game(game) {

        click_engine::make_clickable(roll_all_button, [this]() { logic.rollAllDice(); }, game, roll_all_button_id);
        click_engine::make_clickable(roll_some_button, [this]() { logic.rerollDice(reroll_flags); }, game, roll_some_button_id);

        click_engine::make_clickable(dice1_button, [this]() {reroll_flags[0] = !reroll_flags[0]; std::cout<< "Dice 1 reroll = " << reroll_flags[0] << std::endl;}, game, dice1_button_id, dice1_texture);
        click_engine::make_clickable(dice2_button, [this]() {reroll_flags[1] = !reroll_flags[1]; std::cout<< "Dice 2 reroll = " << reroll_flags[1] << std::endl;}, game, dice2_button_id, dice2_texture);
        click_engine::make_clickable(dice3_button, [this]() {reroll_flags[2] = !reroll_flags[2]; std::cout<< "Dice 3 reroll = " << reroll_flags[2] << std::endl;}, game, dice3_button_id, dice3_texture);
        click_engine::make_clickable(dice4_button, [this]() {reroll_flags[3] = !reroll_flags[3]; std::cout<< "Dice 4 reroll = " << reroll_flags[3] << std::endl;}, game, dice4_button_id, dice4_texture);
        click_engine::make_clickable(dice5_button, [this]() {reroll_flags[4] = !reroll_flags[4]; std::cout<< "Dice 5 reroll = " << reroll_flags[4] << std::endl;}, game, dice5_button_id, dice5_texture);
    };
};

int main() {
    // Initialize the game engine
    Game game;

    // Initialize YazyGame
    YazyGame yazy_game(game);

    // Game loop
    game.loop();

    return 0;
}
