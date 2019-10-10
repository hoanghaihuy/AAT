#ifndef FIND_ARTIFACT_H
#define FIND_ARTIFACT_H
    #include <iostream>
    #include <vector>
    #include "artifact.h"
    #include "chrononaut.h"
    #include "populationCentre.h"

    void findArtifact(Artifact &artifact, std::vector<Chrononaut*> &Chrononauts, int &numberOfJumps, TechEra &techEra, PopulationCentre &popCentre);
#endif
