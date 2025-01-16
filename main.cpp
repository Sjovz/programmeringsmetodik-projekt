#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>
#include "clickable.h"
#include "raylib.h"
#include "yazygame.h"

// TODO 
// game logic för när 2 kast kastats och man är tvungen att välja ett score att spara
// game logic för när spelet är slut och alla poängen sammanställs till en summa
// game logic som styr att spelaren enbart får välja att spara ett score per runda, och inte förändra det efter första sparningen
// see if the yhatzee functions are broken or not, they seem to have some issues
int main() {
    // Initialize the game engine
    Game game;

    // Initialize YazyGame
    YazyGame yazy_game(game);

    // Game loop
    game.loop();

    return 0;
}
