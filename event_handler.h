/************************************************************************************
 * File Name: event_handler.h
 * Author: Erik Sawander
 * Date: 2025-01-15
 * Version: 2.0
 *
 * allows for the handling of deffered actions 
 ************************************************************************************/
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
