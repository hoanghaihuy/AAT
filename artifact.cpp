#include "artifact.h"

Artifact::Artifact() : info(0) {};
Artifact::Artifact(std::string _name, std::string _description, int _estimatePeriod, std::vector<int> _clues)
        : name(_name), description(_description), estimatePeriod(_estimatePeriod), info(0), clues(_clues) {};

void Artifact::display() {
        std::cout << description << std::endl;
}
int Artifact::getPeriod() {
        return estimatePeriod;
}
double Artifact::getInfo() { return info; };
void Artifact::setInfo(double _info) { info = _info; };
void Artifact::gainInfo(double _info) {
        info += _info;
        if (info > 100) info = 100;
};
std::string Artifact::getName() { return name; };
