#include "handlingData.h"
#include "errors.h"
#include "randoms.h"
#include "const.h"

void handlingArtifactData(int numberOfArtifacts, std::vector<Artifact> &Artifacts) {
    std::ifstream inFile;
    inFile.open(ARTIFACT_FILE);
    std::vector<Artifact> array;

    if (!inFile) {
        errorHandling(OPEN_FILE_ERROR, ARTIFACT_FILE);
    }

    std::string line;
    size_t delimiterPos;
    std::string CLUE_DELIMITER = ",";

    while (getline(inFile, line)) {
        Artifact artifact;
        std::string name, description;
        std::vector<int> clues;
        int clue;
        int period;

        delimiterPos = line.find(DELIMITER);
        name = line.substr(0, delimiterPos);
        line.erase(0, delimiterPos + 1);

        delimiterPos = line.find(DELIMITER);
        description = line.substr(0, delimiterPos);
        line.erase(0, delimiterPos + 1);

        delimiterPos = line.find(DELIMITER);
        period = stoi(line.substr(0, delimiterPos));
        line.erase(0, delimiterPos + 1);

        for (int i = 0; i < MAX_CLUE; i++) {
            delimiterPos = line.find(CLUE_DELIMITER);
            clue = stoi(line.substr(0, delimiterPos));
            line.erase(0, delimiterPos + 1);
            clues.push_back(clue);
        }

        artifact = Artifact(name, description, period, clues);
        array.push_back(artifact);

        if (inFile.eof()) break;
    }

    if (numberOfArtifacts < MAX_ARTIFACT) {
        for (int i = 0; i < MAX_ARTIFACT - numberOfArtifacts; i++) {
            int randomIndex = intRandom(MIN_ARTIFACT, MAX_ARTIFACT - i);
            array.erase(array.begin() + randomIndex - 1);
        }
    }
    Artifacts = array;
}

void handlingChrononautsData(std::vector<Chrononaut*> &Chrononauts) {
    Chrononaut *chrononaut = nullptr;

    chrononaut = new JumpEngineer("Jump engineer", JUMP_ENGINEER);
    chrononaut->generateActualAge();
    chrononaut->generateAbility();
    Chrononauts.push_back(chrononaut);

    chrononaut = new Doctor("Doctor", DOCTOR);
    chrononaut->generateActualAge();
    chrononaut->generateAbility();
    Chrononauts.push_back(chrononaut);

    chrononaut = new Historian("Historian", HISTORIAN);
    chrononaut->generateActualAge();
    chrononaut->generateAbility();
    Chrononauts.push_back(chrononaut);

    chrononaut = new Security("Security", SECURITY);
    chrononaut->generateActualAge();
    chrononaut->generateAbility();
    Chrononauts.push_back(chrononaut);

    chrononaut = new ChronoPet("ChronoPet", CHRONO_PET);
    chrononaut->generateActualAge();
    chrononaut->generateAbility();
    Chrononauts.push_back(chrononaut);

}

void handlingEventData(std::vector<Event> &Events) {
    std::ifstream inFile;
    inFile.open(EVENT_FILE);
    std::vector<Event> array;

    if (!inFile) {
        errorHandling(OPEN_FILE_ERROR, EVENT_FILE);
    }

    std::string line;
    size_t delimiterPos;

    while (getline(inFile, line)) {
        std::string name, description;
        EVENT_TYPE eventType;

        delimiterPos = line.find(DELIMITER);
        name = line.substr(0, delimiterPos);
        line.erase(0, delimiterPos + 1);

        description = line;

        if (name == "Information") {
            eventType = INFORMATION;
        } else if (name == "Clue") {
            eventType = CLUE;
        } else if (name == "Artifact") {
            eventType = ARTIFACT;
        } else if (name == "Illness") {
            eventType = ILLNESS;
        } else if (name == "War") {
            eventType = WAR;
        } else if (name == "Technological breakthrough") {
            eventType = TECH_BREAKTHROUGH;
        } else if (name == "Social revolution") {
            eventType = SOCIAL_REVOLUTION;
        } else if (name == "Interaction") {
            eventType = INTERACTION;
        } else if (name == "Meeting") {
            eventType = MEETING;
        }

        Events.push_back(Event(name, description, eventType));

        if (inFile.eof()) break;
    }
}
