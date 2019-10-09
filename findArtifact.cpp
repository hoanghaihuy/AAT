#include "findArtifact.h"
#include "const.h"

void findArtifact(Artifact &artifact, std::vector<Chrononaut*> &Chrononauts, int &numberOfJumps, TechEra &techEra, PopulationCentre &popCentre) {
    JumpEngineer *jumpEngineer = ((JumpEngineer*)Chrononauts[JUMP_ENGINEER]);
    Doctor *doctor = ((Doctor*)Chrononauts[DOCTOR]);
    Historian *historian = ((Historian*)Chrononauts[HISTORIAN]);
    Security *security = ((Security*)Chrononauts[SECURITY]);
    ChronoPet *chronoPet = ((ChronoPet*)Chrononauts[CHRONO_PET]);

    std::cout << "Current handling artifact: ";
    artifact.display();

    if (numberOfJumps > 0) {
        jumpEngineer->makeJump(artifact.getPeriod(), techEra, popCentre);
        popCentre.setTechEra(techEra);
        numberOfJumps--;
    }
    // popCentre.display();

};
