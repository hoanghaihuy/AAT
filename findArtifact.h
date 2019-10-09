#ifndef FIND_ARTIFACT_H
#define FIND_ARTIFACT_H
    #include <iostream>
    #include <vector>
    #include "artifact.h"
    #include "chrononaut.h"
    #include "populationCentre.h"

    void firstJump();

    void findArtifact(Artifact &artifact, std::vector<Chrononaut*> &Chrononauts, int &numberOfJumps, TechEra &TechEra, PopulationCentre &popCentre);
#endif
