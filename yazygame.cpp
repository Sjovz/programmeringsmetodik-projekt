#include "yazygame.h"

YazyGame::YazyGame(Game& game) : game(game) {
        Texture2D dice1_texture = LoadTexture("dice1.png");
        Texture2D dice2_texture = LoadTexture("dice2.png");
        Texture2D dice3_texture = LoadTexture("dice3.png");
        Texture2D dice4_texture = LoadTexture("dice4.png");
        Texture2D dice5_texture = LoadTexture("dice5.png");
        Texture2D dice6_texture = LoadTexture("dice6.png");
        dice_textures.push_back(dice1_texture);
        dice_textures.push_back(dice2_texture);
        dice_textures.push_back(dice3_texture);
        dice_textures.push_back(dice4_texture);
        dice_textures.push_back(dice5_texture);
        dice_textures.push_back(dice6_texture);
        indicators.push_back(dice1_indicator);
        indicators.push_back(dice2_indicator);
        indicators.push_back(dice3_indicator);
        indicators.push_back(dice4_indicator);
        indicators.push_back(dice5_indicator);
        logic.rollAllDice();
        // draw and make clickable rolling buttons
        click_engine::make_clickable(roll_all_button, [this]() { 
            if (score_registered)
            {
                std::generate(reroll_flags.begin(), reroll_flags.end(), [](){return true;}); 
                logic.rollAllDice();
                show_dice(); 
                update_indicators();
                score_registered = false;
                ++round;
                rerolls = 2;
                std::cout << round << std::endl;

                if (round == 13)
                    end_game();
            }
        }, 
        game, roll_all_button_id, "roll all");

        click_engine::make_clickable(roll_some_button, [this]() {
            if (rerolls != 0)
            { 
                logic.rerollDice(reroll_flags); 
                show_dice();
                --rerolls;
            }
        },
        game, roll_some_button_id, "Reroll");

        // draw and make clickable dices
        click_engine::make_clickable(dice1_button, [this]() {reroll_flags[0] = !reroll_flags[0]; std::cout<< "Dice 1 reroll = " << reroll_flags[0] << std::endl; update_indicators();}, game, dice1_button_id, dice1_texture);
        click_engine::make_clickable(dice2_button, [this]() {reroll_flags[1] = !reroll_flags[1]; std::cout<< "Dice 2 reroll = " << reroll_flags[1] << std::endl; update_indicators();}, game, dice2_button_id, dice2_texture);
        click_engine::make_clickable(dice3_button, [this]() {reroll_flags[2] = !reroll_flags[2]; std::cout<< "Dice 3 reroll = " << reroll_flags[2] << std::endl; update_indicators();}, game, dice3_button_id, dice3_texture);
        click_engine::make_clickable(dice4_button, [this]() {reroll_flags[3] = !reroll_flags[3]; std::cout<< "Dice 4 reroll = " << reroll_flags[3] << std::endl; update_indicators();}, game, dice4_button_id, dice4_texture);
        click_engine::make_clickable(dice5_button, [this]() {reroll_flags[4] = !reroll_flags[4]; std::cout<< "Dice 5 reroll = " << reroll_flags[4] << std::endl; update_indicators();}, game, dice5_button_id, dice5_texture);

        show_dice();
        // draw score types text and total sum
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
        click_engine::make_drawable(sum_text, sum_text_id, game, "Sum  =");

        // draw and make clickable score saving buttons
        click_engine::make_clickable(ones_button,[this]() { if (!score_registered) { logic.saveOnesScore(); show_score(); update_partial_score(ones_button_id, ones_button, logic.ones_score); }}, game, ones_button_id);
        click_engine::make_clickable(twoes_button, [this]() { if (!score_registered) if (!score_registered) logic.saveTwosScore(); show_score();update_partial_score(twos_button_id, twoes_button, logic.twos_score);}, game, twos_button_id);
        click_engine::make_clickable(threes_button, [this]() { if (!score_registered) if (!score_registered) logic.saveThreesScore(); show_score(); update_partial_score(threes_button_id, threes_button, logic.threes_score);}, game, threes_button_id);
        click_engine::make_clickable(fours_button, [this]() { if (!score_registered) if (!score_registered) logic.saveFoursScore(); show_score(); update_partial_score(fours_button_id, fours_button, logic.fours_score);}, game, fours_button_id);
        click_engine::make_clickable(fives_button, [this]() { if (!score_registered) if (!score_registered) logic.saveFivesScore(); show_score(); update_partial_score(fives_button_id, fives_button, logic.fives_score);}, game, fives_button_id);
        click_engine::make_clickable(sixes_button, [this]() { if (!score_registered) if (!score_registered) logic.saveSixesScore(); show_score(); update_partial_score(six_button_id, sixes_button, logic.sixes_score);}, game, six_button_id);
        click_engine::make_clickable(three_of_a_kind_button, [this]() { if (!score_registered) if (!score_registered) logic.saveThreeOfAKindScore(); show_score(); update_partial_score(three_of_a_kind_button_id, three_of_a_kind_button, logic.three_of_a_kind_score);}, game, three_of_a_kind_button_id);
        click_engine::make_clickable(four_of_a_kind_button, [this]() { if (!score_registered) if (!score_registered) logic.saveFourOfAKindScore(); show_score(); update_partial_score(four_of_a_kind_button_id, four_of_a_kind_button, logic.four_of_a_kind_score);}, game, four_of_a_kind_button_id);
        click_engine::make_clickable(full_house_button, [this]() { if (!score_registered) if (!score_registered) logic.saveFullHouseScore(); show_score(); update_partial_score(full_house_button_id, full_house_button, logic.full_house_score);}, game, full_house_button_id);
        click_engine::make_clickable(small_straight_button, [this]() { if (!score_registered) if (!score_registered) logic.saveSmallStraightScore(); show_score(); update_partial_score(small_straight_button_id, small_straight_button, logic.small_straight_score);}, game, small_straight_button_id);
        click_engine::make_clickable(large_straight_button, [this]() { if (!score_registered) if (!score_registered) logic.saveLargeStraightScore(); show_score(); update_partial_score(large_straight_button_id, large_straight_button, logic.large_straight_score);}, game, large_straight_button_id);
        click_engine::make_clickable(yazy_button, [this]() { if (!score_registered) if (!score_registered) logic.saveYazyScore(); show_score(); update_partial_score(yazy_button_id, yazy_button, logic.yazy_score);}, game, yazy_button_id);

    };

    void YazyGame::update_partial_score(int id, Rectangle rect, int score)
    {
        score_registered = true;
        game.remove_drawable(id);
        click_engine::make_drawable(rect, id, game, std::to_string(score));
    }

    void YazyGame::show_score()
    {
        game.remove_drawable(sum_text_id);
        click_engine::make_drawable(sum_text, sum_text_id, game, "Sum= " + std::to_string(logic.sum_of_score()));
    }

    void YazyGame::show_dice()
    {
        game.remove_drawable(dice1_button_id);
        game.remove_drawable(dice2_button_id);
        game.remove_drawable(dice3_button_id);
        game.remove_drawable(dice4_button_id);
        game.remove_drawable(dice5_button_id);
        click_engine::make_clickable(dice1_button, [this]() {reroll_flags[0] = !reroll_flags[0]; std::cout<< "Dice 1 reroll = " << reroll_flags[0] << std::endl; update_indicators();}, game, dice1_button_id, dice_textures[logic.dice[0] - 1]);
        click_engine::make_clickable(dice2_button, [this]() {reroll_flags[1] = !reroll_flags[1]; std::cout<< "Dice 2 reroll = " << reroll_flags[1] << std::endl; update_indicators();}, game, dice2_button_id, dice_textures[logic.dice[1] - 1]);
        click_engine::make_clickable(dice3_button, [this]() {reroll_flags[2] = !reroll_flags[2]; std::cout<< "Dice 3 reroll = " << reroll_flags[2] << std::endl; update_indicators();}, game, dice3_button_id, dice_textures[logic.dice[2] -1]);
        click_engine::make_clickable(dice4_button, [this]() {reroll_flags[3] = !reroll_flags[3]; std::cout<< "Dice 4 reroll = " << reroll_flags[3] << std::endl; update_indicators();}, game, dice4_button_id, dice_textures[logic.dice[3] -1]);
        click_engine::make_clickable(dice5_button, [this]() {reroll_flags[4] = !reroll_flags[4]; std::cout<< "Dice 5 reroll = " << reroll_flags[4] << std::endl; update_indicators();}, game, dice5_button_id, dice_textures[logic.dice[4] - 1]);
    }

    void YazyGame::update_indicators()
    {
        for(int i = 0; i != reroll_flags.size(); ++i)
        {
            int id = 34 + i;
            bool rolling = reroll_flags[i];
            game.remove_drawable(id);
            if( !rolling )
                click_engine::make_drawable(indicators[i] ,id ,game);
        }
    }

    void YazyGame::end_game()
    {
        Rectangle end_screen{300, 300, 20, 20};
        Rectangle restart{300, 320, 20, 20};
        click_engine::make_drawable(end_screen, 500, game, "You scored: " + std::to_string(logic.sum_of_score()));
        click_engine::make_clickable(restart, [this](){ reset();},game, 501, "restart");

    }

    void YazyGame::reset()
    {
        // remove the end screen and reset all the stuff 
        game.remove_drawable(500);
        game.remove_drawable(501);
        round = 1;
        rerolls = 2;
        score_registered = false;
        logic.reset();
        logic.rollAllDice();
        update_indicators();
        game.remove_drawable(ones_button_id);
        game.remove_drawable(twos_button_id);
        game.remove_drawable(threes_button_id);
        game.remove_drawable(fours_button_id);
        game.remove_drawable(fives_button_id);
        game.remove_drawable(six_button_id);
        game.remove_drawable(threes_button_id);
        game.remove_drawable(four_of_a_kind_button_id);
        game.remove_drawable(full_house_button_id);
        game.remove_drawable(small_straight_button_id);
        game.remove_drawable(large_straight_button_id);
        game.remove_drawable(yazy_button_id);
        click_engine::make_clickable(ones_button,[this]() { if (!score_registered) logic.saveOnesScore(); show_score(); update_partial_score(ones_button_id, ones_button, logic.ones_score);}, game, ones_button_id);
        click_engine::make_clickable(twoes_button, [this]() { if (!score_registered) logic.saveTwosScore(); show_score();update_partial_score(twos_button_id, twoes_button, logic.twos_score);}, game, twos_button_id);
        click_engine::make_clickable(threes_button, [this]() { if (!score_registered) logic.saveThreesScore(); show_score(); update_partial_score(threes_button_id, threes_button, logic.threes_score);}, game, threes_button_id);
        click_engine::make_clickable(fours_button, [this]() { if (!score_registered) logic.saveFoursScore(); show_score(); update_partial_score(fours_button_id, fours_button, logic.fours_score);}, game, fours_button_id);
        click_engine::make_clickable(fives_button, [this]() { if (!score_registered) logic.saveFivesScore(); show_score(); update_partial_score(fives_button_id, fives_button, logic.fives_score);}, game, fives_button_id);
        click_engine::make_clickable(sixes_button, [this]() { if (!score_registered) logic.saveSixesScore(); show_score(); update_partial_score(six_button_id, sixes_button, logic.sixes_score);}, game, six_button_id);
        click_engine::make_clickable(three_of_a_kind_button, [this]() { if (!score_registered) logic.saveThreeOfAKindScore(); show_score(); update_partial_score(three_of_a_kind_button_id, three_of_a_kind_button, logic.three_of_a_kind_score);}, game, three_of_a_kind_button_id);
        click_engine::make_clickable(four_of_a_kind_button, [this]() { if (!score_registered) logic.saveFourOfAKindScore(); show_score(); update_partial_score(four_of_a_kind_button_id, four_of_a_kind_button, logic.four_of_a_kind_score);}, game, four_of_a_kind_button_id);
        click_engine::make_clickable(full_house_button, [this]() { if (!score_registered) logic.saveFullHouseScore(); show_score(); update_partial_score(full_house_button_id, full_house_button, logic.full_house_score);}, game, full_house_button_id);
        click_engine::make_clickable(small_straight_button, [this]() { if (!score_registered) logic.saveSmallStraightScore(); show_score(); update_partial_score(small_straight_button_id, small_straight_button, logic.small_straight_score);}, game, small_straight_button_id);
        click_engine::make_clickable(large_straight_button, [this]() { if (!score_registered) logic.saveLargeStraightScore(); show_score(); update_partial_score(large_straight_button_id, large_straight_button, logic.large_straight_score);}, game, large_straight_button_id);
        click_engine::make_clickable(yazy_button, [this]() { if (!score_registered) logic.saveYazyScore(); show_score(); update_partial_score(yazy_button_id, yazy_button, logic.yazy_score);}, game, yazy_button_id);
        show_score();
        show_dice();
    }
