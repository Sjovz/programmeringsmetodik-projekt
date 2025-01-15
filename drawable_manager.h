/************************************************************************************
 * File Name: drawable_manager.h
 * Author: Erik Sawander
 * Date: 2025-01-15
 * Version: 2.0
 *
 * this manages the memory for the use of drawable objects and creates a safe interface for adding and deleting them
 ************************************************************************************/
#ifndef DRAWABLE_MANAGER
#define DRAWABLE_MANAGER
#include "clickable.h"
class Drawable_manager {
public:
    void add_drawable(Drawable * drawable);
    // these just move the drawable from drawables to drawables to remove
    void remove_drawable(Drawable* drawable); 
    void remove_drawable(int id);
    // deletes all drawables in drawables_to_remove
    void remove_drawables();
    // these iterators should allways be const
    auto begin() const { return drawables.begin(); }
    auto end() const { return drawables.end(); }
    ~Drawable_manager();
private:
    // ownership
    std::vector<Drawable*> drawables;
    std::vector<Drawable*> drawables_to_remove;
};

#endif // !DRAWABLE_MANAGER
