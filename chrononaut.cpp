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

// Jump engineer
JumpEngineer::JumpEngineer() {};
JumpEngineer::JumpEngineer(std::string _name, int _type)
            : Chrononaut(_name, _type) {};
void JumpEngineer::makeJump() {};

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
