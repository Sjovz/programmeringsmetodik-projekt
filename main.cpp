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
