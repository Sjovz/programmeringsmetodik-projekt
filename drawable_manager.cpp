#include "drawable_manager.h"

void Drawable_manager::add_drawable(Drawable* drawable){drawables.push_back(drawable);}

void Drawable_manager::remove_drawable(int id)
{
    auto it = std::find_if(drawables.begin(), drawables.end(), [id](const auto & drawable){return drawable->get_id() == id;});
    if (it != drawables.end()) {
       drawables_to_remove.push_back(*it);
       drawables.erase(it);
    }
}

void Drawable_manager::remove_drawable(Drawable* drawable) 
{
    auto it = std::find(drawables.begin(), drawables.end(), drawable);
    if (it != drawables.end()) {
       drawables.erase(it);
    }
    drawables_to_remove.push_back(drawable);
}

void Drawable_manager::remove_drawables()
{
    for (Drawable* drawable: drawables_to_remove) 
    {
        delete drawable;  
        drawable = nullptr;
    }
    drawables_to_remove.clear();
}

Drawable_manager::~Drawable_manager()
{
    for (Drawable* drawable : drawables) 
    {
        if (drawable != nullptr)
        {
            delete drawable;
            drawable = nullptr;
        }
    }
    drawables.clear();

    for (Drawable* drawable : drawables_to_remove) {
        if (drawable != nullptr)
        {
            delete drawable;
            drawable = nullptr;
        }
    }
    drawables_to_remove.clear();
}
