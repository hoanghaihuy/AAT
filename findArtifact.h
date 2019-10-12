#ifndef FIND_ARTIFACT_H
#define FIND_ARTIFACT_H
    #include <iostream>
    #include <vector>
    #include "artifact.h"
    #include "chrononaut.h"
    #include "populationCentre.h"
    #include "event.h"
    #include "handlingData.h"

    Event generateEvent(int, std::vector<Event> &Events);
    void findArtifact(Artifact &artifact, std::vector<Chrononaut*> &Chrononauts, int &numberOfJumps, TechEra &techEra, PopulationCentre &popCentre);
#endif
