#include "event.h"

Event::Event() : name(""), description(""), level(0), occurChance(0) {};
Event::Event(std::string _name, std::string _description, EVENT_TYPE _type) : name(_name), description(_description), type(_type) {};
void Event::generateLevel(PopulationCentre) {

};
void Event::display() {
    std::cout << name << " " << description << " " << type << " " << occurChance << std::endl;
};
int Event::getOccurChance() { return occurChance; };
void Event::setOccurChance(int chance) { occurChance = chance; };
EVENT_TYPE Event::getEventType() { return type; };

