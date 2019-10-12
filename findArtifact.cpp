#include "findArtifact.h"
#include "const.h"
#include "randoms.h"

void findArtifact(Artifact &artifact, std::vector<Chrononaut*> &Chrononauts, int &numberOfJumps, TechEra &techEra, PopulationCentre &popCentre) {
    std::vector<Event> Events;
    handlingEventData(Events);

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
        popCentre.setYearSpent(0);
        numberOfJumps--;

        // chrononauts affect on the level of tech era
        // then the tech era affect on the rest of elements of popCentre
        techEra.affectLevel(averageAbilityLevel);
        popCentre.techEraAffected(techEra);
        popCentre.display();

        while (artifact.getInfo() < FINISH_ARTIFACT) {
            if (popCentre.getYearSpent() < 10 && artifact.getInfo() < FINISH_ARTIFACT) {
                // minimum event could occur in a year is 0, maximum is 2
                double info = 0;
                Event event;
                bool hasGainedInfo = false;
                int numberOfEvent = intRandom(0, 2);
                if (numberOfEvent != 0) {
                    for (int i = 0; i < numberOfEvent; i++) {
                        // event occur
                        event = generateEvent(popCentre.getYearSpent(), Events);
                        event.generateLevel(popCentre);
                        event.display();

                        // 1 team member would be affected by the event
                        int memberIndex = intRandom(0, Chrononauts.size());

                        // handling event
                        // after handled an event, the ability level of chrononaut would be improved
                        switch (event.getEventType()) {
                            case INFORMATION:
                                info = historian->findInfo(event, true);
                                historian->improveAbility(techEra);
                                historian->solvedEvent(info);
                                hasGainedInfo = true;
                                break;
                            case CLUE:
                                break;
                            case ARTIFACT:
                                info = 0;
                                hasGainedInfo = true;
                                artifact.gainInfo(FINISH_ARTIFACT - artifact.getInfo());
                                break;
                            case ILLNESS:
                                // affect popCentre
                                popCentre.decreasePop(true);

                                // affect chrononaut
                                Chrononauts[i]->getIllness();
                                double damage = doctor->cure(event, popCentre);
                                Chrononauts[i]->beingDamaged(damage);
                                doctor->improveAbility(techEra);
                                break;
                            case WAR:
                                // affect popCentre, increase tech level and growth rate, decrease number of population and change level and growth rate based on new techEra
                                techEra.increaseGrowRate();
                                techEra.increaseLevel();
                                popCentre.setTechEra(techEra);
                                popCentre.decreasePop();
                                popCentre.population->generatePopImpact(techEra);

                                // affect chrononaut
                                Chrononauts[i]->getWar();
                                double damage = chronoPet->protect(event, popCentre);
                                Chrononauts[i]->beingDamaged(damage);
                                chronoPet->improveAbility(techEra);
                                break;
                            case TECH_BREAKTHROUGH:
                                techEra.affectedByBreakthrough();
                                popCentre.population->generatePopImpact(techEra);
                                popCentre.setTechEra(techEra);
                                for (int j = 0; j < popCentre.functionalities.size(); j++) {
                                    popCentre.functionalities[i].setGrowRate(techEra.getGrowRate());
                                }
                                break;
                            case SOCIAL_REVOLUTION:
                                popCentre.population->affectedByRevolution(popCentre);
                                break;
                            case INTERACTION:
                                security->interactLocal(event, techEra, popCentre);
                                break;
                            case MEETING:
                            
                                break;
                            default:
                                break;
                        }
                    }
                }

                // in each year stepping forward, there will be information available
                if (hasGainedInfo == false) {
                    info = historian->findInfo(event, false);
                }
                artifact.gainInfo(info);

                // handle data when step forward year by year
                ++popCentre;
                for (int i = 0; i < Chrononauts.size(); i++) {
                    if (Chrononauts[i]->isDead() != true) {
                        Chrononauts[i]->increaseTravelAge();
                    }
                }
            } else {
                artifact.gainInfo(FINISH_ARTIFACT - artifact.getInfo());
            }
        }
    }
    // popCentre.display();

};

Event generateEvent(int spentYear, std::vector<Event> &Events) {
    // spent year is limited to 10.
    // The closer of spent year to 10, the bigger of the chance to generate event related to information and clue
    // chance to generate findind artifact event is constant and equal to 4%

    // handling occur chance of each event
    int point = 0;
    if (spentYear == 0) {
        // in the first year, chance to generate others event is equal to each other (12%)
        for (int i = 0; i < Events.size(); i++) {
            if (Events[i].getEventType() == ARTIFACT) {
                point += CHANCE_FIND_ARTIFACT;
            } else {
                point += CHANCE_FIND_OTHER;
            }
            Events[i].setOccurChance(point);
        }
    } else {
        // from the second year, chance to generate info or clue event increases 3% year by year
        // meanwhile, chance to generate others decreases 1% year by year
        for (int i = 0; i < Events.size(); i++) {
            if (Events[i].getEventType() == INFORMATION || Events[i].getEventType() == CLUE) {
                point += (CHANCE_FIND_OTHER + (spentYear * 3));
            } else if (Events[i].getEventType() == ARTIFACT) {
                point += CHANCE_FIND_ARTIFACT;
            } else {
                point += (CHANCE_FIND_OTHER - spentYear);
            }
            Events[i].setOccurChance(point);
        }
    }

    int randomNum = intRandom(1, 100);
    Event event;

    for (int i = 0; i < Events.size(); i++) {
        if (randomNum < Events[i].getOccurChance()) {
            event = Events[i];
            break;
        }
    }
    return event;
};
