#include "artifact.h"

Artifact::Artifact() {};
Artifact::Artifact(std::string _name, std::string _description, int _estimatePeriod)
        : name(_name), description(_description), estimatePeriod(_estimatePeriod) {};

void Artifact::display() {
        std::cout << name << ", " << description << ", " << estimatePeriod << std::endl;
}
int Artifact::getPeriod() {
        return estimatePeriod;
}
