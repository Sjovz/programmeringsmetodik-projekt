#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

enum category
{
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SAMETHREE,
    SAMEFOUR,
    HOUSE,
    STRAIGHT,
    YAZY,

    AMOUNT
};

class yazygame
{
    public:
    int dice[5];
    bool categoryUsed[13] = {false};
    int scores[13] = {0};

    yazygame()
    {
        rollAllDice();
    }

    void rollAllDice()
    {
        for(int &tarning : dice)
        {
            tarning = rand() % 6 + 1;
        }
    }

    void rerollDice(bool reroll[5])
    {
        for (int i = 0; i < 5; ++i)
        {
            if (reroll[i])
            {
                dice[i] = rand() % 6 + 1;
            }
        }
    }

    void printDice() const
    {
        for(int tarning : dice)
        {
            std::cout << tarning << " ";
        }
        std::cout << std::endl;
    }

    int same_number(int match, const int dice[5]) // function to determinate how many points you get for matching numbers, ex. ones or twos
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

    int same_three(int match, const int dice[5]) // function to determinate how many points you get for matching three numbers
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

    int same_four(int match, const int dice[5]) // function to determinate how many points you get for matching four numbers
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

    int house(const int dice[5])
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

    int straight(int dice[5])
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

    int yazy(int dice[5])
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

};

int main()
{
    srand(static_cast<unsigned>(time(0)));

    yazygame game;

    for(int turn = 0; turn < 13; turn++)
    {
        std::cout << "\nTurn " << turn + 1 << ": Rolling dice...\n";
        game.rollAllDice();
        game.printDice();

        //rerolls
        int rerolls = 0;
        while (rerolls < 2)
        {
            char rerollChoice;
            std::cout << "Do you want to re-roll? (y/n): ";
            std::cin >> rerollChoice;
            if (rerollChoice == 'n')
                break;

            std::cout << "Enter which dice to re-roll (1-5 with spaces in between, enter 0 to stop): ";
            bool reroll[5] = {false};
            int index;
            while (std::cin >> index && index != 0)
            {
                if (index >= 1 && index <= 5)
                {
                    reroll[index - 1] = true;
                }
            }
            game.rerollDice(reroll);
            game.printDice();
            rerolls++;
        }

        // choose category
        int categoryChoice;
        do
        {
            std::cout << "Choose a category 0 to 10: ";
            std::cin >> categoryChoice;
            if (categoryChoice < 0 || categoryChoice >= AMOUNT || game.categoryUsed[categoryChoice])
            {
                std::cout << "Invalid or already used category. Try again.\n";
            }
        } while (categoryChoice < 0 || categoryChoice >= AMOUNT || game.categoryUsed[categoryChoice]);

        // calculate score from the category
        int score = 0;
        switch (categoryChoice)
        {
        case ONE:
            score = game.same_number(1, game.dice);
            break;
        case TWO:
            score = game.same_number(2, game.dice);
            break;
        case THREE:
            score = game.same_number(3, game.dice);
            break;
        case FOUR:
            score = game.same_number(4, game.dice);
            break;
        case FIVE:
            score = game.same_number(5, game.dice);
            break;
        case SIX:
            score = game.same_number(6, game.dice);
            break;
        case SAMETHREE:
            score = game.same_number(3, game.dice);
            break;
        case SAMEFOUR:
            score = game.same_number(4, game.dice);
            break;
        case HOUSE:
            score = game.house(game.dice);
            break;
        case STRAIGHT:
            score = game.straight(game.dice);
            break;
        case YAZY:
            score = game.yazy(game.dice);
            break;
        }

        game.scores[categoryChoice] = score;
        game.categoryUsed[categoryChoice] = true;

        std::cout << "Scored " << score << " points in category " << categoryChoice << ".\n";
    }

    // final score
    int totalScore = 0;
    for (int i = 0; i < AMOUNT; ++i)
    {
        totalScore += game.scores[i];
    }
    std::cout << "\nGame Over! Final score: " << totalScore << "\n";

    return 0;
}
// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.