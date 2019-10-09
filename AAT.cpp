#include <iostream>
#include <fstream>
#include <vector>
#include "errors.h"
#include "randoms.h"
#include "handlingData.h"
#include "artifact.h"
#include "chrononaut.h"
#include "const.h"
#include "populationCentre.h"
#include "findArtifact.h"
using namespace std;

int main(int argc, char *argv[]) {
    srand(time(0));
    vector<Artifact> Artifacts;
    vector<Chrononaut*> Chrononauts;

    if (argc != 3) {
        errorHandling(COMMAND_LINE_ERROR);
    } else {
        int numberOfArtifacts = atoi(argv[1]);
        int numberOfJumps = atoi(argv[2]);

        if (numberOfArtifacts < MIN_ARTIFACT || numberOfArtifacts > MAX_ARTIFACT) {
            errorHandling(ARTIFACT_INPUT_ERROR);
        }
        if (numberOfJumps < MIN_JUMP || numberOfJumps > MAX_JUMP) {
            errorHandling(JUMP_INPUT_ERROR);
        }

        handlingArtifactData(numberOfArtifacts, Artifacts);
        handlingChrononautsData(Chrononauts);

        for (int i = 0; i < Chrononauts.size(); i++) {
            Chrononauts[i]->display();
        }

        // for (int i = 0; i < Artifacts.size(); i++) {
        //     Artifacts[i].display();
        // }

        TechEra currentTechEra(TECHNOLOGY_ERA::MODERN_AGE);
        int currentPopNum = intRandom(MIN_OF_METROPOLIS, MAX_OF_METROPOLIS);
        PopulationCentre currentPopCentre(currentTechEra, currentPopNum, MODERN_YEAR);
        // currentPop.display();

        for (int i = 0; i < numberOfArtifacts; i++) {
            findArtifact(Artifacts[i], Chrononauts, numberOfJumps, currentTechEra, currentPopCentre);
            if (numberOfJumps <= 0) break;
        }

        return 0;
    }
}
