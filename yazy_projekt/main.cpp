#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "yazygame.h"
#include "game.h"

// all we need to do now is add sprites and set up another layer of abstraction to get the yatzee class to interact the new graphics/click handling class 
// if we have time we can split the responsibilities better in the game class so that it isnt both the event listener and the game at the same time.
// and also maybe add an abstract class for the command handling so that its not all gross lamda captures :) 
int main()
{
    Game game;
}
/*int main()*/
/*{*/
/*    srand(static_cast<unsigned>(time(0)));*/
/**/
/*    yazygame game;*/
/**/
/*    for(int turn = 0; turn < 13; turn++)*/
/*    {*/
/*        std::cout << "\nTurn " << turn + 1 << ": Rolling dice...\n";*/
/*        game.rollAllDice();*/
/*        game.printDice();*/
/**/
/*        //rerolls*/
/*        int rerolls = 0;*/
/*        while (rerolls < 2)*/
/*        {*/
/*            char rerollChoice;*/
/*            std::cout << "Do you want to re-roll? (y/n): ";*/
/*            std::cin >> rerollChoice;*/
/*            if (rerollChoice == 'n')*/
/*                break;*/
/**/
/*            std::cout << "Enter which dice to re-roll (1-5 with spaces in between, enter 0 to stop): ";*/
/*            bool reroll[5] = {false};*/
/*            int index;*/
/*            while (std::cin >> index && index != 0)*/
/*            {*/
/*                if (index >= 1 && index <= 5)*/
/*                {*/
/*                    reroll[index - 1] = true;*/
/*                }*/
/*            }*/
/*            game.rerollDice(reroll);*/
/*            game.printDice();*/
/*            rerolls++;*/
/*        }*/
/**/
/*        // choose category*/
/*        int categoryChoice;*/
/*        do*/
/*        {*/
/*            std::cout << "Choose a category 0 to 10: ";*/
/*            std::cin >> categoryChoice;*/
/*            if (categoryChoice < 0 || categoryChoice >= AMOUNT || game.categoryUsed[categoryChoice])*/
/*            {*/
/*                std::cout << "Invalid or already used category. Try again.\n";*/
/*            }*/
/*        } while(categoryChoice < 0 || categoryChoice >= AMOUNT || game.categoryUsed[categoryChoice]);*/
/**/
/*        // calculate score from the category*/
/*        int score = 0;*/
/*        switch (categoryChoice)*/
/*        {*/
/*        case ONE:*/
/*            score = game.same_number(1, game.dice);*/
/*            break;*/
/*        case TWO:*/
/*            score = game.same_number(2, game.dice);*/
/*            break;*/
/*        case THREE:*/
/*            score = game.same_number(3, game.dice);*/
/*            break;*/
/*        case FOUR:*/
/*            score = game.same_number(4, game.dice);*/
/*            break;*/
/*        case FIVE:*/
/*            score = game.same_number(5, game.dice);*/
/*            break;*/
/*        case SIX:*/
/*            score = game.same_number(6, game.dice);*/
/*            break;*/
/*        case SAMETHREE:*/
/*            score = game.same_number(3, game.dice);*/
/*            break;*/
/*        case SAMEFOUR:*/
/*            score = game.same_number(4, game.dice);*/
/*            break;*/
/*        case HOUSE:*/
/*            score = game.house(game.dice);*/
/*            break;*/
/*        case STRAIGHT:*/
/*            score = game.straight(game.dice);*/
/*            break;*/
/*        case YAZY:*/
/*            score = game.yazy(game.dice);*/
/*            break;*/
/*        }*/
/**/
/*        game.scores[categoryChoice] = score;*/
/*        game.categoryUsed[categoryChoice] = true;*/
/**/
/*        std::cout << "Scored " << score << " points in category " << categoryChoice << ".\n";*/
/*    }*/
/**/
/*    // final score*/
/*    int totalScore = 0;*/
/*    for (int i = 0; i < AMOUNT; ++i)*/
/*    {*/
/*        totalScore += game.scores[i];*/
/*    }*/
/*    std::cout << "\nGame Over! Final score: " << totalScore << "\n";*/
/**/
/*    return 0;*/
/*}*/
// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
