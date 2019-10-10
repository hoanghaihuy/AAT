#include <math.h>
#include "chrononaut.h"
#include "randoms.h"
#include "const.h"

// Chrononaut
Chrononaut::Chrononaut() {};
Chrononaut::Chrononaut(std::string _name, int _type)
            : name(_name), type(_type) {};
void Chrononaut::increaseTravelAge() {
    travelAge++;
};
void Chrononaut::generateActualAge() {
    actualAge = intRandom(MIN_AGE, MAX_AGE);
}
void Chrononaut::display() {
    std::cout << name << ": " << actualAge << ", " << abilityLevel << std::endl;
}
void Chrononaut::generateAbility() {
    if (type == JUMP_ENGINEER) {
        abilityLevel = 100;
    } else {
        abilityLevel = intRandom(MIN_ABILITY, MAX_ABILITY);
    }
};
void Chrononaut::improveAbility() {};
void Chrononaut::affectAbility() {};
int Chrononaut::getAbilityLevel() { return abilityLevel; };

// Jump engineer
JumpEngineer::JumpEngineer() {};
JumpEngineer::JumpEngineer(std::string _name, int _type)
            : Chrononaut(_name, _type) {};
TECHNOLOGY_ERA JumpEngineer::findTechEra(int currentYear) {
    if (currentYear <= END_OF_EARLY_AGE) {
        return EARLY_AGE;
    } else if (currentYear <= END_OF_MIDDLE_AGE) {
        return MIDDLE_AGE;
    } else {
        return MODERN_AGE;
    }
};
void JumpEngineer::makeJump(int period, TechEra &techEra, PopulationCentre &popCentre) {
    // the year in the past that the team jumps to
    int currentPastYear = popCentre.getCurrentYear();
    currentPastYear -= period;

    // find technology era of the year just jumped to
    TECHNOLOGY_ERA currentTechEraType = findTechEra(currentPastYear);
    techEra = TechEra(currentTechEraType);

    // generate new number of population based on the grow rate of population,
    // the current number of population in the current popCentre and the period of time
    Population *pop = popCentre.population;
    int newPopNum = pop->getPopNum() * (pow((1.0 - pop->getGrowRate()), double(period)));
    // std::cout << "current pop: " << pop->getPopNum() << " " << "new pop: " << newPopNum << std::endl;
    popCentre = PopulationCentre(techEra, newPopNum, currentPastYear);
    popCentre.display();
};

// Doctor
Doctor::Doctor() {};
Doctor::Doctor(std::string _name, int _type)
            : Chrononaut(_name, _type) {};
void Doctor::cure() {};

// Historian
Historian::Historian() {};
Historian::Historian(std::string _name, int _type)
            : Chrononaut(_name, _type) {};
void Historian::findInfo() {};

// Security
Security::Security() {};
Security::Security(std::string _name, int _type)
            : Chrononaut(_name, _type) {};
void Security::interactLocal() {};

// ChronoPet
ChronoPet::ChronoPet() {};
ChronoPet::ChronoPet(std::string _name, int _type)
            : Chrononaut(_name, _type) {};
void ChronoPet::protect() {};
