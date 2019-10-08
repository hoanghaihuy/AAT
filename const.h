#ifndef CONST_H
#define CONST_H
    #include <iostream>

    // error
    const int COMMAND_LINE_ERROR = 1;
    const int OPEN_FILE_ERROR = 2;
    const int FILE_FORMAT_ERROR = 3;
    const int ARTIFACT_INPUT_ERROR = 4;
    const int JUMP_INPUT_ERROR = 5;

    // artifact
    const std::string ARTIFACT_FILE = "Artifacts.txt";
    const int MIN_ARTIFACT = 1;
    const int MAX_ARTIFACT = 5;
    const int MIN_JUMP = 1;
    const int MAX_JUMP = 10;
    const std::string DELIMITER = ";";

    // chrononaut
    const int MAX_AGE = 40;
    const int MIN_AGE = 25;
    const int MAX_ABILITY = 80;
    const int MIN_ABILITY = 60;
    const int JUMP_ENGINEER = 1;
    const int DOCTOR = 2;
    const int HISTORIAN = 3;
    const int SECURITY = 4;
    const int CHRONO_PET = 5;

    // population centre
    enum POPULATION_CENTRE {HAMLET, VILLAGE, TOWN, CITY, METROPOLIS};

    // techonology era
    enum TECHNOLOGY_ERA {RENAISSANCE, MIDDLE_AGE, INFORMATION_AGE};

    // functionality
    enum FUNCTION_TYPE {DEFENDANT, HISTORY, HEALTH};

    // population
    const int MIN_OF_HAMLET = 10;
    const int MAX_OF_HAMLET = 999;
    const int MIN_OF_VILLAGE = 1000;
    const int MAX_OF_VILLAGE = 9999;
    const int MIN_OF_TOWN = 10000;
    const int MAX_OF_TOWN = 99999;
    const int MIN_OF_CITY = 100000;
    const int MAX_OF_CITY = 999999;
    const int MIN_OF_METROPOLIS = 1000000;
    const int MAX_OF_METROPOLIS = 1500000;
#endif