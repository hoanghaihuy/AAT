#include "event.h"
#include "randoms.h"

Event::Event() : name(""), description(""), level(0), occurChance(0) {};
Event::Event(std::string _name, std::string _description, EVENT_TYPE _type) : name(_name), description(_description), type(_type) {};
void Event::generateLevel(PopulationCentre popCentre) {
    double elementLevelSum = popCentre.population->getLevel() + popCentre.technology->getLevel();
    for (int i = 0; i < popCentre.functionalities.size(); i++) {
        elementLevelSum += popCentre.functionalities[i].getLevel();
    }

    double averageElementLevel = elementLevelSum / (2 + popCentre.functionalities.size());
    double eventPureLevel = intRandom(50, 100);

    level = (averageElementLevel + eventPureLevel) / 2;
};
void Event::display() {
    std::cout << description << std::endl;
};
int Event::getOccurChance() { return occurChance; };
void Event::setOccurChance(int chance) { occurChance = chance; };
EVENT_TYPE Event::getEventType() { return type; };
double Event::getLevel() { return level; };
