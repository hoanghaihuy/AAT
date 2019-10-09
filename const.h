#ifndef CONST_H
#define CONST_H
    #include <iostream>

    const int MODERN_YEAR = 2525;

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
    const int JUMP_ENGINEER = 0;
    const int DOCTOR = 1;
    const int HISTORIAN = 2;
    const int SECURITY = 3;
    const int CHRONO_PET = 4;

    // population centre
    enum POPULATION_CENTRE {HAMLET, VILLAGE, TOWN, CITY, METROPOLIS};

    // techonology era
    enum TECHNOLOGY_ERA {EARLY_AGE, MIDDLE_AGE, MODERN_AGE};
    const int END_OF_EARLY_AGE = 999;
    const int END_OF_MIDDLE_AGE = 1999;

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
