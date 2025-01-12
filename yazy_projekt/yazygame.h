#ifndef YAZYGAME_H
#define YAZYGAME_H

#include "category.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

class yazygame
{
public:
    int dice[5];
    bool categoryUsed[13];
    int scores[13];

    yazygame();
    void rollAllDice();
    void rerollDice(bool reroll[5]);
    void printDice() const;

    //rules
    int same_number(int match, const int dice[5]);
    int same_three(int match, const int dice[5]);
    int same_four(int match, const int dice[5]);
    int house(const int dice[5]);
    int straight(int dice[5]);
    int yazy(int dice[5]);
};

#endif
