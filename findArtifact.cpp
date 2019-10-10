#include "findArtifact.h"
#include "const.h"

void findArtifact(Artifact &artifact, std::vector<Chrononaut*> &Chrononauts, int &numberOfJumps, TechEra &techEra, PopulationCentre &popCentre) {
    JumpEngineer *jumpEngineer = ((JumpEngineer*)Chrononauts[JUMP_ENGINEER]);
    Doctor *doctor = ((Doctor*)Chrononauts[DOCTOR]);
    Historian *historian = ((Historian*)Chrononauts[HISTORIAN]);
    Security *security = ((Security*)Chrononauts[SECURITY]);
    ChronoPet *chronoPet = ((ChronoPet*)Chrononauts[CHRONO_PET]);

    double abilityLevelSum;
    for (int i = 0; i < Chrononauts.size(); i++) {
        abilityLevelSum += Chrononauts[i]->getAbilityLevel();
    }
    double averageAbilityLevel = double(abilityLevelSum / Chrononauts.size());

    std::cout << "Current handling artifact: ";
    artifact.display();

    // the jump engineer make the jump action to the past
    // then the techEra and popCentre would be updated
    if (numberOfJumps > 0) {
        jumpEngineer->makeJump(artifact.getPeriod(), techEra, popCentre);
        popCentre.setTechEra(techEra);
        numberOfJumps--;
        // chrononauts affect on the level of tech era
        techEra.affectLevel(averageAbilityLevel);
        popCentre.techEraAffected(techEra);
        popCentre.display();
    }
    // popCentre.display();

};
