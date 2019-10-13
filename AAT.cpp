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

        cout << "The team includes " << Chrononauts.size() << " members: " << endl;
        for (int i = 0; i < Chrononauts.size(); i++) {
            Chrononauts[i]->display();
        }

        cout << "There are " << Artifacts.size() << " need to be found: ";
        for (int i = 0; i < Artifacts.size(); i++) {
            cout << Artifacts[i].getName();
            if (i < Artifacts.size() - 1) cout << ", ";
        }
        cout << endl;



        int currentPopNum = intRandom(MIN_OF_METROPOLIS, MAX_OF_METROPOLIS);
        bool finished = false;

        for (int i = 0; i < numberOfArtifacts; i++) {
            // the team will back to modern date to handout the finished artifact before handling the next artifact
            // this step no need to waste the jump thanks to the function of time machine
            TechEra currentTechEra(TECHNOLOGY_ERA::MODERN_AGE);
            PopulationCentre currentPopCentre(currentTechEra, currentPopNum, MODERN_YEAR);
            if (i == 0) {
                cout << "Current living status: \n";
                currentPopCentre.display();
                cout << endl;
                cout << "START..." << endl;
            }

            if (i > 0) cout << "HANDLING NEXT ARTIFACT...\n";
            cout << "Current handling artifact: " << Artifacts[i].getName() << endl;
            cout << "Number of jumps left: " << numberOfJumps << endl;
            findArtifact(Artifacts[i], Chrononauts, numberOfJumps, currentTechEra, currentPopCentre);
            if (Artifacts[i].getInfo() >= 100) {
                cout << "The information about " << Artifacts[i].getName() << " has been found: ";
                Artifacts[i].display();
                if (i == numberOfArtifacts - 1) {
                    cout << "BACKING...\nALL ARTIFACTS HAS FOUND." << endl;
                    finished = true;
                } else {
                    cout << "BACKING...\n" << endl;
                }
            }
            if (numberOfJumps <= 0 && finished == false) {
                cout << "There is no more jumps to make." << endl;
                for (int j = i + 1; j < numberOfArtifacts; j++) {
                    cout << Artifacts[j].getName();
                    if (j < numberOfArtifacts - 1) cout << ", ";
                }
                cout << " have/has not found\n" << endl;
                break;
            }
            if(Chrononauts[JUMP_ENGINEER]->getType() != JUMP_ENGINEER && finished == false) {
                cout << "The jump engineer has been lost/dead, the team has been stuck." << endl;
                break;
            }
        }

        for (int i = 0; i < Chrononauts.size(); i++) {
            Chrononauts[i]->display();
        }

        for (int i = 0; i < Chrononauts.size(); i++) {
            delete Chrononauts[i];
        }
        // delete currentPopCentre.population;
        // delete currentPopCentre.technology;

        return 0;
    }
}
