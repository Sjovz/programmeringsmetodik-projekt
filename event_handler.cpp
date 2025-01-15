#include "event_handler.h"
void Event_handler::process_actions() 
{
    for (auto& action : deffered_actions) {
        action();
    }
    deffered_actions.clear();
}

void Event_handler::add_action(std::function<void()> action) 
{
    deffered_actions.push_back(action);
}
