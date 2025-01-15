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

    Texture2D dice1_texture = LoadTexture("C:/Users/Ellev/ClionProjects/programmeringsmetodik-projekt/Data/dice1.png");
    Texture2D dice2_texture = LoadTexture("C:/Users/Ellev/ClionProjects/programmeringsmetodik-projekt/Data/dice2.png");
    Texture2D dice3_texture = LoadTexture("C:/Users/Ellev/ClionProjects/programmeringsmetodik-projekt/Data/dice3.png");
    Texture2D dice4_texture = LoadTexture("C:/Users/Ellev/ClionProjects/programmeringsmetodik-projekt/Data/dice4.png");
    Texture2D dice5_texture = LoadTexture("C:/Users/Ellev/ClionProjects/programmeringsmetodik-projekt/Data/dice5.png");
    Texture2D dice6_texture = LoadTexture("C:/Users/Ellev/ClionProjects/programmeringsmetodik-projekt/Data/dice6.png");


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
