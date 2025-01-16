#ifndef YAZYGAME
#define YAZYGAME
#include "game.h"
#include "yazyfunct.h"

///@brief Declaration of YazyGame class.
///@details The class handles starting of the game, loading in textures, creating rectangles that acts as buttons and text.
class YazyGame {
    private:
    ///@Brief Referance to the main game object.
    ///@Details This member holds a reference to the game object which handles setting up the window
    Game& game;

    ///@brief YazyFunct object
    ///@details This member holds a referance to the ýazyfunct object which helps handle game logic such as score calculation.
    yazyfunct logic;

    // game logic counters
    ///@brief Current round of the game.
    ///@details This counts the current round of the game.
    int round = 1;

    ///@brief Amount of rerolls remaining.
    ///@Details Counts how many rerolls the player has left in the current run.
    int rerolls = 2;

    ///@brief Flag to keep track of if a scored has been chosen for the round.
    ///@details Helps ensure only 1 score is saved per round.
    bool score_registered = false;

    ///@breif Flags for which dice to reroll.
    ///@details A vector of booleans that indicates which dice to be rerolled and which dice to keep.
    std::vector<bool> reroll_flags = {true, true, true, true, true};

    ///@breif Rectangle for the Roll All button.
    ///details Defines a rectangle object with set position and size.
    Rectangle roll_all_button = {200, 450, 50, 20};

    ///@breif Rectangle for the reroll button.
    ///@details Defines a rectangle object with set position and size.
    Rectangle roll_some_button = {300, 450, 50, 20};

    ///@brief Rectangles for the dices.
    ///@details Defines rectangles for all the dice buttons, sets their position and size.
    Rectangle dice1_button = {50, 500, 50, 50};
    Rectangle dice2_button = {150, 500, 50, 50};
    Rectangle dice3_button = {250, 500, 50, 50};
    Rectangle dice4_button = {350, 500, 50, 50};
    Rectangle dice5_button = {450, 500, 50, 50};

    ///@brief Rectangles for indicating which dice to reroll.
    ///@details Defines rectangles for indicating
    Rectangle dice1_indicator = {50, 520, 50, 20};
    Rectangle dice2_indicator = {150, 520, 50, 20};
    Rectangle dice3_indicator = {250, 520, 50, 20};
    Rectangle dice4_indicator = {350, 520, 50, 20};
    Rectangle dice5_indicator = {450, 520, 50, 20};
    std::vector<Rectangle> indicators;

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

    // roll buttons id's
    const int roll_all_button_id = 0;
    const int roll_some_button_id = 1;

    // dice buttons id's
    const int dice1_button_id = 2;
    const int dice2_button_id = 3;
    const int dice3_button_id = 4;
    const int dice4_button_id = 5;
    const int dice5_button_id = 6;

    //const int roll_all_text_id = 7; // not used
    //const int roll_some_text_id = 8; // not used

    //the score text id's
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

    // the save score buttons id's
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

    const int dice1_indicator_id = 34;
    const int dice2_indicator_id =  35;
    const int dice3_indicator_id = 36;
    const int dice4_indicator_id = 37;
    const int dice5_indicator_id = 38;

    // textures
    std::vector<Texture2D> dice_textures;
    // set the partial score counter and make it so that it cant be set again 
    void update_partial_score(int id, Rectangle rect, int score);
    // show total score 
    void show_score();
    // update the face of the dice 
    void show_dice();
    // update the state of the indicators 
    void update_indicators();
    // show the end game screen
    void end_game();
    // restart the game 
    void reset();
    public:
    YazyGame(Game& game); 
};

#endif // !YAZYGAME
