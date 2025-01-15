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

    Rectangle roll_all_button = {200, 450, 50, 20};
    Rectangle roll_some_button = {300, 450, 50, 20};

    Rectangle dice1_button = {50, 500, 50, 50};
    Rectangle dice2_button = {150, 500, 50, 50};
    Rectangle dice3_button = {250, 500, 50, 50};
    Rectangle dice4_button = {350, 500, 50, 50};
    Rectangle dice5_button = {450, 500, 50, 50};

    Rectangle ones_text = {550, 20, 50, 10};
    Rectangle twoes_text = {550, 60, 50, 10};
    Rectangle threes_text = {550, 100, 50, 10};
    Rectangle fours_text = {550, 140, 50, 10};
    Rectangle fives_text = {550, 180, 50, 10};
    Rectangle six_text = {550, 220, 50, 10};
    Rectangle three_of_a_kind_text = {550, 260, 50, 10};
    Rectangle four_of_a_kind_text = {550, 300, 50, 10};
    Rectangle full_house_text = {550, 340, 50, 10};
    Rectangle small_straight_text = {550, 380, 50, 10};
    Rectangle large_straight_text = {550, 420, 50, 10};
    Rectangle yazy_text = {550, 460, 50, 10};

    Rectangle sum_text = {550, 550, 50, 10};

    Rectangle ones_button = {750, 20, 30, 25};
    Rectangle twoes_button = {750, 60, 30, 25};
    Rectangle threes_button = {750, 100, 30, 25};
    Rectangle fours_button = {750, 140, 30, 25};
    Rectangle fives_button = {750, 180, 30, 25};
    Rectangle sixes_button = {750, 220, 30, 25};
    Rectangle three_of_a_kind_button = {750, 260, 30, 25};
    Rectangle four_of_a_kind_button = {750, 300, 30, 25};
    Rectangle full_house_button = {750, 340, 30, 25};
    Rectangle small_straight_button = {750, 380, 30, 25};
    Rectangle large_straight_button = {750, 420, 30, 25};
    Rectangle yazy_button = {750, 460, 30, 30};

    const int roll_all_button_id = 0;
    const int roll_some_button_id = 1;

    const int dice1_button_id = 2;
    const int dice2_button_id = 3;
    const int dice3_button_id = 4;
    const int dice4_button_id = 5;
    const int dice5_button_id = 6;

    const int roll_all_text_id = 7; // not used
    const int roll_some_text_id = 8; // not used

    const int ones_text_id = 9;
    const int twos_text_id = 10;
    const int threes_text_id = 11;
    const int fours_text_id = 12;
    const int fives_text_id = 13;
    const int six_text_id = 14;
    const int three_of_a_kind_text_id = 15;
    const int four_of_a_kind_text_id = 16;
    const int full_house_text_id = 17;
    const int small_straight_text_id = 18;
    const int large_straight_text_id = 19;
    const int yazy_text_id = 20;

    const int sum_text_id = 21;

    const int ones_button_id = 22;
    const int twos_button_id = 23;
    const int threes_button_id = 24;
    const int fours_button_id = 25;
    const int fives_button_id = 26;
    const int six_button_id = 27;
    const int three_of_a_kind_button_id = 28;
    const int four_of_a_kind_button_id = 29;
    const int full_house_button_id = 30;
    const int small_straight_button_id = 31;
    const int large_straight_button_id = 32;
    const int yazy_button_id = 33;

    const int sum_button_id = 34;

    Texture2D dice1_texture = LoadTexture("C:/Users/Ellev/ClionProjects/programmeringsmetodik-projekt/Data/dice1.png");
    Texture2D dice2_texture = LoadTexture("C:/Users/Ellev/ClionProjects/programmeringsmetodik-projekt/Data/dice2.png");
    Texture2D dice3_texture = LoadTexture("C:/Users/Ellev/ClionProjects/programmeringsmetodik-projekt/Data/dice3.png");
    Texture2D dice4_texture = LoadTexture("C:/Users/Ellev/ClionProjects/programmeringsmetodik-projekt/Data/dice4.png");
    Texture2D dice5_texture = LoadTexture("C:/Users/Ellev/ClionProjects/programmeringsmetodik-projekt/Data/dice5.png");
    Texture2D dice6_texture = LoadTexture("C:/Users/Ellev/ClionProjects/programmeringsmetodik-projekt/Data/dice6.png");

    public:
    YazyGame(Game& game) : game(game) {

        click_engine::make_clickable(roll_all_button, [this]() { logic.rollAllDice(); }, game, roll_all_button_id, "Roll all");
        click_engine::make_clickable(roll_some_button, [this]() { logic.rerollDice(reroll_flags); }, game, roll_some_button_id, "Reroll");

        click_engine::make_clickable(dice1_button, [this]() {reroll_flags[0] = !reroll_flags[0]; std::cout<< "Dice 1 reroll = " << reroll_flags[0] << std::endl;}, game, dice1_button_id, dice1_texture);
        click_engine::make_clickable(dice2_button, [this]() {reroll_flags[1] = !reroll_flags[1]; std::cout<< "Dice 2 reroll = " << reroll_flags[1] << std::endl;}, game, dice2_button_id, dice2_texture);
        click_engine::make_clickable(dice3_button, [this]() {reroll_flags[2] = !reroll_flags[2]; std::cout<< "Dice 3 reroll = " << reroll_flags[2] << std::endl;}, game, dice3_button_id, dice3_texture);
        click_engine::make_clickable(dice4_button, [this]() {reroll_flags[3] = !reroll_flags[3]; std::cout<< "Dice 4 reroll = " << reroll_flags[3] << std::endl;}, game, dice4_button_id, dice4_texture);
        click_engine::make_clickable(dice5_button, [this]() {reroll_flags[4] = !reroll_flags[4]; std::cout<< "Dice 5 reroll = " << reroll_flags[4] << std::endl;}, game, dice5_button_id, dice5_texture);

        click_engine::make_drawable(ones_text, ones_text_id, game, "Ones");
        click_engine::make_drawable(twoes_text, twos_text_id, game, "Twoes");
        click_engine::make_drawable(threes_text, threes_text_id, game, "Threes");
        click_engine::make_drawable(fours_text, fours_text_id, game, "Fours");
        click_engine::make_drawable(fives_text, fives_text_id, game, "Fives");
        click_engine::make_drawable(six_text, six_text_id, game, "Sixes");
        click_engine::make_drawable(three_of_a_kind_text, three_of_a_kind_text_id, game, "Three of a kind");
        click_engine::make_drawable(four_of_a_kind_text, four_of_a_kind_text_id, game, "Four of a kind");
        click_engine::make_drawable(full_house_text, full_house_text_id, game, "Full house");
        click_engine::make_drawable(small_straight_text, small_straight_text_id, game, "Small straight");
        click_engine::make_drawable(large_straight_text, large_straight_text_id, game, "Large straight");
        click_engine::make_drawable(yazy_text, yazy_text_id, game, "Yazy");

        click_engine::make_drawable(sum_text, sum_text_id, game, "Sum");

        click_engine::make_clickable(ones_button,[this]() { logic.saveOnesScore(); }, game, ones_button_id);
        click_engine::make_clickable(twoes_button, [this]() { logic.saveTwosScore(); }, game, twos_button_id);
        click_engine::make_clickable(threes_button, [this]() { logic.saveThreesScore(); }, game, threes_button_id);
        click_engine::make_clickable(fours_button, [this]() { logic.saveFoursScore(); }, game, fours_button_id);
        click_engine::make_clickable(fives_button, [this]() { logic.saveFivesScore(); }, game, fives_button_id);
        click_engine::make_clickable(sixes_button, [this]() { logic.saveSixesScore(); }, game, six_button_id);
        click_engine::make_clickable(three_of_a_kind_button, [this]() { logic.saveThreeOfAKindScore(); }, game, three_of_a_kind_button_id);
        click_engine::make_clickable(four_of_a_kind_button, [this]() { logic.saveFourOfAKindScore(); }, game, four_of_a_kind_button_id);
        click_engine::make_clickable(full_house_button, [this]() { logic.saveFullHouseScore(); }, game, full_house_button_id);
        click_engine::make_clickable(small_straight_button, [this]() { logic.saveSmallStraightScore(); }, game, small_straight_button_id);
        click_engine::make_clickable(large_straight_button, [this]() { logic.saveLargeStraightScore(); }, game, large_straight_button_id);
        click_engine::make_clickable(yazy_button, [this]() { logic.saveYazyScore(); }, game, yazy_button_id);

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
