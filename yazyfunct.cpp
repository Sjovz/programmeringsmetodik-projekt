#include "yazyfunct.h"

yazyfunct::yazyfunct() : categoryUsed{false}, scores{0}
{
    rollAllDice();
}

void yazyfunct::rollAllDice()
{
    for(int &tarning : dice)
    {
        tarning = rand() % 6 + 1;
    }
    printDice();
}

void yazyfunct::rerollDice(std::vector<bool> reroll_flags)
{
    for(int i = 0; i < 5; ++i)
    {
        if(reroll_flags[i])
          {
            dice[i] = rand() % 6 + 1;
          }
    }
    printDice();
}

void yazyfunct::printDice() const
{
    for(int tarning : dice)
    {
        std::cout << tarning << " ";
    }
    std::cout << std::endl;
}

int yazyfunct::same_number(int match, const int dice[5]) // function to determinate how many points you get for matching numbers, ex. ones or twos
{
    return std::accumulate(dice, dice + 5, 0, [match](int sum, int num){return sum + (num == match ? num : 0);}); 
}

int yazyfunct::house(const int dice[5])
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

int yazyfunct::straight(int dice[5]) //this is ugly, but it works
{
    std::sort(dice, dice + 5);
    auto func = [](int first, int second){return !(second == first + 1);};
    auto result_it = std::adjacent_find(dice, dice + 5, func);
    if (result_it == dice) 
    {
        return (std::adjacent_find(dice + 1, dice + 5, func) == dice + 5) ? 30 : 0; 
    }
    if (result_it == dice + 5) return 40; // big straight 
    if (result_it == dice + 3) return 30; // small straight
    return 0;
}

int yazyfunct::yazy(int dice[5])
{
    if (std::adjacent_find(dice, dice + 5) == dice + 5)
        return 50; 
    else 
        return 0;
}



