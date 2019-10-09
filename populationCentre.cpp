#include <iomanip>
#include <cmath>
#include "populationCentre.h"
#include "randoms.h"

// Technology Era class functions
TechEra::TechEra() : name(""), type(EARLY_AGE), level(0), growRate(0) {};
TechEra::TechEra(TECHNOLOGY_ERA _type) : type(_type) {
    switch (type) {
        case EARLY_AGE:
            name = "Early Age";
            generateLevel(0, 25);
            generateGrowRate(0.01, 0.005);
            break;
        case MIDDLE_AGE:
            name = "Middle Age";
            generateLevel(25, 50);
            generateGrowRate(0.02, 0.007);
            break;
        case MODERN_AGE:
            name = "Modern Age";
            generateLevel(50, 100);
            generateGrowRate(0.03, 0.009);
            break;
        default:
            break;
    }
};
TechEra& TechEra::operator=(const TechEra& other) {
    if (this != &other) {
        this->setLevel(other.level);
        this->setGrowRate(other.growRate);
        this->name = other.name;
        this->type = other.type;
    }
    return *this;
};
void TechEra::generateLevel(int min, int max) {
    level = intRandom(min, max);
};
void TechEra::generateGrowRate(double mean, double stddev) {
    growRate = doubleRandom(mean, stddev);
};
void TechEra::setLevel(int _level) { level = _level; };
int TechEra::getLevel() {
    return level;
};
void TechEra::setGrowRate(double _growRate) { growRate = _growRate; };
double TechEra::getGrowRate() {
    return growRate;
};
void TechEra::display() {
    std::cout << "Technology era: " << name << ": " << level << ", " << std::setiosflags(std::ios::fixed | std::ios::showpoint) << std::setprecision(5) << growRate << std::endl;
};
TECHNOLOGY_ERA TechEra::getTechEra() { return type; }

// Element class functions
void Element::generateLevel(int min, int max) {
    level = intRandom(min, max);
};
void Element::setLevel(int _level) { level = _level; };
int Element::getLevel() {
    return level;
};
void Element::setGrowRate(double _growRate) { growRate = _growRate; };
double Element::getGrowRate() {
    return growRate;
};

// Functionality class functions
Functionality::Functionality() : name(""), type(HISTORY) {}
Functionality::Functionality(FUNCTION_TYPE _type, std::string _name) : type(_type), name(_name) {
    switch (type) {
        case DEFENDANT:
            if (name == "Police Station") {
                generateLevel(50, 75);
            } else {
                generateLevel(75, 100);
            }
            break;
        case HISTORY:
            if (name == "Story Teller") {
                generateLevel(0, 25);
            } else if (name == "Book shop") {
                generateLevel(25, 50);
            } else if (name == "Library") {
                generateLevel(50, 75);
            } else {
                generateLevel(75, 100);
            }
            break;
        case HEALTH:
            if (name == "Clinic") {
                generateLevel(25, 50);
            } else if (name == "Medical Centre") {
                generateLevel(50, 75);
            } else {
                generateLevel(75, 100);
            }
            break;
        default:
            break;
    }
};
void Functionality::display() {
    std::cout << name;
};

// Population class functions
Population::Population() : number(0) {
    Element::setLevel(0);
    Element::setGrowRate(0);
};
Population::Population(int _number) : number(_number) {};
void Population::generatePopImpact(TechEra _techEra) {
    // the level and growth rate of population is based on level and growth rate of technology era
    double full = 100;
    double diff = intRandom(50, 100);
    int levelPop = (diff / full) * _techEra.getLevel();
    diff = intRandom(0, 50);
    double growRatePop = (diff / full) * _techEra.getGrowRate();
    Element::setLevel(levelPop);
    Element::setGrowRate(growRatePop);
};
int Population::getPopNum() { return number; };
void Population::display() {
    std::cout << "population: " << number << ", level: " << Element::getLevel() << ", growth rate: " << Element::getGrowRate() << std::endl;
};

// PopulationCentre class functions
PopulationCentre::PopulationCentre() {
    technology = new TechEra();
    functionalities = {};
    population = new Population();
    name = "";
    populationType = HAMLET;
};
PopulationCentre::PopulationCentre(TechEra _techEra, int _popNum, int _currentYear) {
    technology = &_techEra;
    currentYear = _currentYear;
    population = new Population(_popNum);
    population->generatePopImpact(_techEra);

    if (_popNum > MIN_OF_HAMLET && _popNum < MAX_OF_HAMLET) {
        populationType = HAMLET;
    } else if (_popNum > MIN_OF_VILLAGE && _popNum < MAX_OF_VILLAGE) {
        populationType = VILLAGE;
    } else if (_popNum > MIN_OF_TOWN && _popNum < MAX_OF_TOWN) {
        populationType = TOWN;
    } else if (_popNum > MIN_OF_CITY && _popNum < MAX_OF_CITY) {
        populationType = CITY;
    } else if (_popNum > MIN_OF_METROPOLIS && _popNum < MAX_OF_METROPOLIS) {
        populationType = METROPOLIS ;
    }

    switch (populationType) {
        case HAMLET:
            name = "Hamlet";
            break;
        case VILLAGE:
            name = "Village";
            functionalities.push_back(Functionality(HISTORY, "Story Teller"));
            break;
        case TOWN:
            name = "Town";
            functionalities.push_back(Functionality(HISTORY, "Book Shop"));
            functionalities.push_back(Functionality(HEALTH, "Clinic"));
            break;
        case CITY:
            name = "City";
            functionalities.push_back(Functionality(HISTORY, "Library"));
            functionalities.push_back(Functionality(HEALTH, "Medical Centre"));
            functionalities.push_back(Functionality(DEFENDANT, "Police Station"));
            break;
        case METROPOLIS:
            name = "Metropolis";
            functionalities.push_back(Functionality(HISTORY, "Library"));
            functionalities.push_back(Functionality(HEALTH, "Hospital"));
            functionalities.push_back(Functionality(DEFENDANT, "Army"));
            break;
        default:
            name = "Hamlet";
            break;
    }
};
// PopulationCentre& PopulationCentre::operator++() {};
void PopulationCentre::display() {
    technology->display();
    std::cout << "This is a " << name << " with ";
    population->display();
    if (functionalities.size() > 0) {
        std::cout << "This " << name << " has: ";
        for (int i = 0; i < functionalities.size(); i++) {
            functionalities[i].display();
            if (i != functionalities.size() - 1) std::cout << ", ";
        }
    } else {
        std::cout << "This " << name << " does not have any functionalities.";
    }
    std::cout << std::endl;
};
int PopulationCentre::getCurrentYear() {
    return currentYear;
};
void PopulationCentre::setCurrentYear(int year) {
    currentYear = year;
};
PopulationCentre::~PopulationCentre() {
    // delete population;
}
