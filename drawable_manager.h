#ifndef DRAWABLE_MANAGER
#define DRAWABLE_MANAGER
#include "clickable.h"
class Drawable_manager {
public:
    void add_drawable(Drawable * drawable);
    void remove_drawable(Drawable* drawable); 
    void remove_drawable(int id);
    void remove_drawables();
    void draw();
    auto begin() const { return drawables.begin(); }
    auto end() const { return drawables.end(); }
private:
    std::vector<Drawable*> drawables;
    std::vector<Drawable*> drawables_to_remove;
};

#endif // !DRAWABLE_MANAGER
