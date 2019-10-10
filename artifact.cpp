#include "artifact.h"

Artifact::Artifact() : info(0) {};
Artifact::Artifact(std::string _name, std::string _description, int _estimatePeriod)
        : name(_name), description(_description), estimatePeriod(_estimatePeriod), info(0) {};

void Artifact::display() {
        std::cout << name << ", " << description << ", " << estimatePeriod << std::endl;
}
int Artifact::getPeriod() {
        return estimatePeriod;
}
double Artifact::getInfo() { return info; };
void Artifact::gainInfo(double _info) { info += _info; };
