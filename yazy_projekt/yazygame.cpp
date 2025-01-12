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
    printDice();
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
    return std::accumulate(dice, dice + 5, 0, [match](int sum, int num){return sum + (num == match ? num : 0);}); 
}

int yazygame::house(const int dice[5])
{
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
    auto count_number = [&dice](int value) {
        return std::count_if(dice, dice + 5, [value](int d) { return d == value; });
    };
    bool has_three = std::any_of(numbers.begin(), numbers.end(), 
                                [&count_number](int i) { return count_number(i) == 3; });
    bool has_two = std::any_of(numbers.begin(), numbers.end(), 
                              [&count_number](int i) { return count_number(i) == 2; });
    
    return (has_three && has_two) ? 25 : 0;
}

int yazygame::straight(int dice[5]) //this is ugly, but it works 
{
    std::sort(dice, dice + 5);
    auto func = [](int first, int second){return !(second == first + 1);};
    auto result_it = std::adjacent_find(dice, dice + 5, func);
    if (result_it == dice) 
    {
        return (std::adjacent_find(dice + 1, dice + 5, func) == dice + 5) ? 30 : 0; 
    }
    if (result_it == dice + 5) return 40;
    if (result_it == dice + 3) return 30;
    return 0;
}

int yazygame::yazy(int dice[5])
{
    auto func = [](int value) -> bool 
    {
        return true;
    };
    if (std::adjacent_find(dice, dice + 5) == dice + 5)
        return 50; 
    else 
        return 0;
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

