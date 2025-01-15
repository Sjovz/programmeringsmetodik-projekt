## Game class

Implements a basic game engine that relies on clicking on things and running their callback functions to advance the game
Could easily be added on to in order to make a more complete game engine
The documentation for click_engine is also included here as they are tightly coupled, perhaps in the future the class should be expanded to have an api for them

The window for the game will have a resolution of 800 by 600 

```Game::Game()```
call this once to run the game 
```Game::loop()``` 
remove a drawable from the game
```Game::remove_drawable(int id)``` 

## click_engine class

The click engine class allows the user to create drawables and clickables that automatically subscribe to the listener and memory manager in an instance of Game

``` c++
static void make_clickable(Rectangle rect, std::function<void()> onClick, Game& owner, int id);
static void make_clickable(Rectangle rect, std::function<void()> onClick, Game& owner, int id, Texture2D texture);
static void make_drawable(Rectangle rect, int id, Game& game);
static void make_drawable(Rectangle rect, int id, Game& game, Texture2D texture);
static void make_clickable(Rectangle rect, std::function<void()> onClick, Game& owner, int id, std::string text);
static void make_drawable(Rectangle rect, int id, Game& game, std::string text);
```

using only this you should be able to create a basic but functioning game
