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
    yazyfunct logic; // Using the game logic class
    const int DICE_COUNT = 5;

    Rectangle reset_button;
    Rectangle roll_button;
    Rectangle reroll_buttons[5]; // Reroll buttons for individual dice ?
    bool reroll_flags[5] = {false, false, false, false, false}; // Flags for dice to reroll and not to reroll

    Texture2D dice_textures[6];

    void reset_game() {
        logic = yazyfunct(); // Reset the logic object
        for (bool& reroll_flag : reroll_flags) {
            reroll_flag = false;
        }
        std::cout << "Game reset haha hoppas jag" << std::endl;
    }

    void roll_all_dice() {
        logic.rollAllDice();
    }

    void reroll_selected_dice() {
        logic.rerollDice(reroll_flags);
        for (bool& reroll_flag : reroll_flags) {
            reroll_flag = false; // Reset reroll flags
        }
    }

public:
    YazyGame(Game& game) : game(game) {
        reset_button = {10.0f, 10.0f, 100.0f, 50.0f};
        roll_button = {300.0f, 500.0f, 200.0f, 50.0f};

        float dice_x_start = 250.0f; // Starting position for dice, CHANGE TO MAKE LOOKEY NICEYNICE
        for (int i = 0; i < DICE_COUNT; ++i) {
            reroll_buttons[i] = {dice_x_start + i * 70.0f, 450.0f, 50.0f, 50.0f};
        }

        // Load dice textures, auto does dice1, dice2... hopefully
        for (int i = 0; i < 6; ++i) {
            std::string path = "C:/Users/Ellev/CLionProjects/yazy/Data/dice" + std::to_string(i + 1) + ".png";
            dice_textures[i] = LoadTexture(path.c_str());
        }

        // Make buttons clickable
        click_engine::make_clickable(reset_button, [this]() { reset_game(); }, &game);
        click_engine::make_clickable(roll_button, [this]() { roll_all_dice(); }, &game);
        for (int i = 0; i < DICE_COUNT; ++i) {
            click_engine::make_clickable(reroll_buttons[i], [this, i]() {
                reroll_flags[i] = !reroll_flags[i];
            }, &game);
        }
    }

    ~YazyGame() { // no memory leak pls
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

        // Draw dice and reroll buttons
        float dice_x_start = 250.0f; // Starting position for dice
        for (int i = 0; i < DICE_COUNT; ++i) {
            int dice_value = logic.getDiceValue(i) - 1; // Get the dice value from yazyfunct
            DrawTexture(dice_textures[dice_value], dice_x_start + i * 70.0f, 400.0f, WHITE);

            // Draw reroll buttons below each die
            Color button_color = reroll_flags[i] ? BLUE : LIGHTGRAY;
            DrawRectangleRec(reroll_buttons[i], button_color);
            DrawText("Reroll", reroll_buttons[i].x + 5.0f, reroll_buttons[i].y + 15.0f, 20, BLACK);
        }

        // Draw scores example: same_number for ones,  adde rest later
        int ones_score = logic.same_number(1, logic.getDiceArray());
        DrawText(("Score for Ones: " + std::to_string(ones_score)).c_str(), 10, 100, 20, BLACK);

        EndDrawing();
    }
};

int main() {
    Game game;
    YazyGame yazy_game(game);

    game.loop([&]() {
        yazy_game.draw();
    });

    return 0;
}
