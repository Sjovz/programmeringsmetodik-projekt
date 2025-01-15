#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H
#include <functional>

#define EVENT_HANDLER_H
class Event_handler {
public: 
    void add_action(std::function<void()> action);
    void process_actions(); 
private: 
    std::vector<std::function<void()>> deffered_actions;
};
#endif // !EVENT_HANDLER_H
