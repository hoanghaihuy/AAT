#include <math.h>
#include "chrononaut.h"
#include "randoms.h"
#include "const.h"

// Chrononaut
Chrononaut::Chrononaut() {};
Chrononaut::Chrononaut(std::string _name, int _type)
            : name(_name), type(_type), health(100) {};
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
void Chrononaut::improveAbility(TechEra techEra) {
    if (abilityLevel < 100) {
        abilityLevel += (techEra.getGrowRate() * abilityLevel);
    }
};
void Chrononaut::affectAbility() {};
int Chrononaut::getAbilityLevel() { return abilityLevel; };
double Chrononaut::getHealth() { return health; };
void Chrononaut::setHealth(double _health) { health = _health; };
void Chrononaut::beingDamaged(double _health) { health -= _health; };
void Chrononaut::getIllness() {
    std::cout << name << " is getting sick." << std::endl;
}
void Chrononaut::getWar() {
    std::cout << name << " is damaged because of war." << std::endl;
}
bool Chrononaut::isDead() {
    return health <= 0;
};

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
    popCentre = PopulationCentre(techEra, newPopNum, currentPastYear);
};

// Doctor
Doctor::Doctor() {};
Doctor::Doctor(std::string _name, int _type)
            : Chrononaut(_name, _type) {};
double Doctor::cure(Event event, PopulationCentre popCentre) {
    double damage = 0;
    double functionalitiesLevel = 0;
    for (int i = 0; i < popCentre.functionalities.size(); i++) {
        if (popCentre.functionalities[i].getType() == HEALTH) {
            functionalitiesLevel = popCentre.functionalities[i].getLevel();
        }
    }
    double generalLevel = (getAbilityLevel() + functionalitiesLevel) / 2;
    if (event.getLevel() > generalLevel) {
        damage = event.getLevel() - generalLevel;
    }
    std::cout << "The doctor has cured the patient, the patient has lost " << damage << " health." << std::endl;
    return damage;
};

// Historian
Historian::Historian() {};
Historian::Historian(std::string _name, int _type)
            : Chrononaut(_name, _type) {};
double Historian::findInfo(Event event, bool isEvent) {
    double info = 0;
    if (isEvent) {
        info = (Chrononaut::getAbilityLevel() / 100) * event.getLevel();
    } else {
        double generalInfo = intRandom(10, 20);
        info = (Chrononaut::getAbilityLevel() / 100) * generalInfo;
    }
    return info;
};
void Historian::solvedEvent(double info) {
    std::cout << "Historian has found " << info << "% of the current artifact." << std::endl;
};

// Security
Security::Security() {};
Security::Security(std::string _name, int _type)
            : Chrononaut(_name, _type) {};
void Security::interactLocal(Event event, TechEra &techEra, PopulationCentre &popCentre) {
    // if positive effect (1), the tech era level and growth rate are increased (teaching new tech)
    // if negative effect (2), the number of population is decreased (conflict and fighting with locals)
    int effect = intRandom(1, 2);
    if (effect = 1) {
        techEra.increaseGrowRate();
        techEra.increaseLevel();
        popCentre.setTechEra(techEra);
        popCentre.population->generatePopImpact(techEra);
        for (int i = 0; i < popCentre.functionalities.size(); i++) {
            popCentre.functionalities[i].setGrowRate(techEra.getGrowRate());
        }
        std::cout << "The chrononauts had positive effect on locals which has increased technology level to " << techEra.getLevel();
    } else {
        popCentre.decreasePop();
        std::cout << "The chrononauts had negative effect on locals which has decreased number of population to " << popCentre.population->getPopNum();
    }
};

// ChronoPet
ChronoPet::ChronoPet() {};
ChronoPet::ChronoPet(std::string _name, int _type)
            : Chrononaut(_name, _type) {};
double ChronoPet::protect(Event event, PopulationCentre popCentre) {
    double damage = 0;
    double functionalitiesLevel = 0;
    for (int i = 0; i < popCentre.functionalities.size(); i++) {
        if (popCentre.functionalities[i].getType() == DEFENDANT) {
            functionalitiesLevel = popCentre.functionalities[i].getLevel();
        }
    }
    double generalLevel = (getAbilityLevel() + functionalitiesLevel) / 2;
    if (event.getLevel() > generalLevel) {
        damage = event.getLevel() - generalLevel;
    }
    std::cout << "The chrono-pet has protected the victim, the victim has lost " << damage << " health." << std::endl;
    return damage;
};
