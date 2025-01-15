#ifndef YAZYGAME_H
#define YAZYGAME_H

#include "category.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

class yazyfunct
{
private:
    int ones_score = 0;
    int twos_score = 0;
    int threes_score = 0;
    int fours_score = 0;
    int fives_score = 0;
    int sixes_score = 0;
    int three_of_a_kind_score = 0;
    int four_of_a_kind_score = 0;
    int full_house_score = 0;
    int small_straight_score = 0;
    int large_straight_score = 0;
    int yazy_score = 0;


public:
    int dice[5];
    bool categoryUsed[13];
    int scores[13];

    yazyfunct();
    void rollAllDice();
    void rerollDice(std::vector<bool> reroll_flags);
    void printDice() const;

    // save score functions very proffesional
    void saveOnesScore();
    void saveTwosScore();
    void saveThreesScore();
    void saveFoursScore();
    void saveFivesScore();
    void saveSixesScore();
    void saveThreeOfAKindScore();
    void saveFourOfAKindScore();
    void saveFullHouseScore();
    void saveSmallStraightScore();
    void saveLargeStraightScore();
    void saveYazyScore();

    //rules
    int same_number(int match, const int dice[5]);
    int same_three(int match, const int dice[5]);
    int same_four(int match, const int dice[5]);
    int house(const int dice[5]);
    int straight(int dice[5]);
    int yazy(int dice[5]);
};

#endif
