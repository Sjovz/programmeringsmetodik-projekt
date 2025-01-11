#include "yazygame.h"

yazygame::yazygame() : categoryUsed{false}, scores{0}
{
    rollAllDice();
}

void yazygame::rollAllDice()
    {
        for(int &tarning : dice)
        {
            tarning = rand() % 6 + 1;
        }
    }

void yazygame::rerollDice(bool reroll[5])
{
    for(int i = 0; i < 5; ++i)
    {
        if(reroll[i])
          {
            dice[i] = rand() % 6 + 1;
          }
    }
}

void yazygame::printDice() const
    {
        for(int tarning : dice)
        {
            std::cout << tarning << " ";
        }
        std::cout << std::endl;
    }

int yazygame::same_number(int match, const int dice[5]) // function to determinate how many points you get for matching numbers, ex. ones or twos
    {
        int sum = 0;
        for (int i = 0; i < 5; i++)
        {
            if(dice[i] == match)
            {
                sum += dice[i];
            }
        }
        return sum;
    }

int yazygame::same_three(int match, const int dice[5]) // function to determinate how many points you get for matching three numbers
    {
        int sum = 0;
        int count = 3;
        for (int i = 0; i < 5; i++)
        {
            if (dice[i] == match)
            {
                sum += dice[i];
                count++;
            }
        }
        if (count == 3)
        {
            return sum;
        }
        return 0;
    }

int yazygame::same_four(int match, const int dice[5]) // function to determinate how many points you get for matching four numbers
    {
        int sum = 0;
        int count = 3;
        for (int i = 0; i < 5; i++)
        {
            if (dice[i] == match)
            {
                sum += dice[i];
                count++;
            }
        }
        if (count == 4)
        {
            return sum;
        }
        return 0;
    }

int yazygame::house(const int dice[5])
    {
        int count[7] = {0};

        // count how many times each number occurs
        for (int i = 0; i < 5; i++)
        {
            count[dice[i]]++;
        }

        int threegroup;
        int twogroup = 0;

        for (int it = 1; it < 6; it++)
        {
            if (count[it] == 3)
            {
                threegroup++;
            }
            else if (count[it] == 2)
                {
                twogroup++;
            }
        }

        if (threegroup == 1 && twogroup == 1)
        {
            return 25;
        }

        return 0;
    }

int yazygame::straight(int dice[5])
    {
        bool found_numbers[7] = {false};

        for (int i = 0; i < 5; i++)
        {
            if(dice[i] >= 1 && dice[i] <= 6)
            {
                found_numbers[i] = true;
            }
        }

        bool small = found_numbers[1] && found_numbers[2] && found_numbers[3] && found_numbers[4] && found_numbers[5];
        bool big = found_numbers[2] && found_numbers[3] && found_numbers[4] && found_numbers[5] && found_numbers[6];

        if (small || big)
        {
            return 40;
        }
        return 0;
    }

int yazygame::yazy(int dice[5])
    {
        for (int i = 0; i < 5; i++)
        {
            if (dice[i] != dice[0])
            {
                return 0;
            }
        }
        return 50;
    }
