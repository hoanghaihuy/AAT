#include "event.h"

Event::Event() : name(""), description(""), level(0) {};
Event::Event(std::string _name, std::string _description) : name(_name), description(_description) {};
void Event::generateLevel(PopulationCentre) {

};
void Event::display() {
    std::cout << name << " " << description << std::endl;
};
