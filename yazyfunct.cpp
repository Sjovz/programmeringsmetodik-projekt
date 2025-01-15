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

void yazyfunct::saveOnesScore() {
    ones_score = same_number(1, dice);
    std::cout << "Ones score saved: " << ones_score << std::endl;
}

void yazyfunct::saveTwosScore() {
    twos_score = same_number(2, dice);
    std::cout << "Twos score saved: " << twos_score << std::endl;
}

void yazyfunct::saveThreesScore() {
    threes_score = same_number(3, dice);
    std::cout << "Threes score saved: " << threes_score << std::endl;
}

void yazyfunct::saveFoursScore() {
    fours_score = same_number(4, dice);
    std::cout << "Fours score saved: " << fours_score << std::endl;
}

void yazyfunct::saveFivesScore() {
    fives_score = same_number(5, dice);
    std::cout << "Fives score saved: " << fives_score << std::endl;
}

void yazyfunct::saveSixesScore() {
    sixes_score = same_number(6, dice);
    std::cout << "Sixes score saved: " << sixes_score << std::endl;
}

void yazyfunct::saveThreeOfAKindScore() {
    // Array to help count n amount of dice values present
    int count[7] = {0}; // Indices 0 unused

    // Count the occurrences of each dice value
    for (int i = 0; i < 5; ++i) {
        count[dice[i]]++;
    }

    // Check if any value appears 3 or more times
    for (int i = 1; i <= 6; ++i) {
        if (count[i] >= 3) {
            // If valid, calculate the total score as the sum of all dice
            three_of_a_kind_score = std::accumulate(dice, dice + 5, 0);
            std::cout << "Three of a Kind score saved: " << three_of_a_kind_score << std::endl;
            return;
        }
    }

    // If no "Three of a Kind" is found, score is 0
    three_of_a_kind_score = 0;
    std::cout << "No Three of a Kind. Score saved: " << three_of_a_kind_score << std::endl;
}

void yazyfunct::saveFourOfAKindScore() {
    // Array to count occurrences of each dice value (1 to 6)
    int count[7] = {0}; // Indices 0 to 6 (0 unused)

    // Count the occurrences of each dice value
    for (int i = 0; i < 5; ++i) {
        count[dice[i]]++;
    }

    // Check if any value appears 4 or more times
    for (int i = 1; i <= 6; ++i) {
        if (count[i] >= 4) {
            // If valid, calculate the total score as the sum of all dice
            four_of_a_kind_score = std::accumulate(dice, dice + 5, 0);
            std::cout << "Four of a Kind score saved: " << four_of_a_kind_score << std::endl;
            return;
        }
    }

    // If no "Four of a Kind" is found, score is 0
    four_of_a_kind_score = 0;
    std::cout << "No Four of a Kind. Score saved: " << four_of_a_kind_score << std::endl;
}

void yazyfunct::saveFullHouseScore() {
    full_house_score = house(dice);
    std::cout << "Full House score saved: " << full_house_score << std::endl;
}

void yazyfunct::saveSmallStraightScore() {
    int result = straight(dice);
    small_straight_score = (result == 30) ? 30 : 0; // Save 30 points if it's a Small Straight
    std::cout << "Small Straight score saved: " << small_straight_score << std::endl;
}

void yazyfunct::saveLargeStraightScore() {
    int result = straight(dice);
    large_straight_score = (result == 40) ? 40 : 0; // Save 40 points if it's a Large Straight
    std::cout << "Large Straight score saved: " << large_straight_score << std::endl;
}

void yazyfunct::saveYazyScore() {
    yazy_score = yazy(dice); // Call the yazy function and save the result
    std::cout << "Yazy score saved: " << yazy_score << std::endl;
}

