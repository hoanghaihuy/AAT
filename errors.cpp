#include "errors.h"
#include "const.h"

// handling error function
void errorHandling(int errorType, std::string fileName) {
    std::string errorMessage = "";
    switch (errorType) {
        case COMMAND_LINE_ERROR:
            errorMessage = "Input arguments in command line is in WRONG FORMAT.\nOnly 2 INPUTS are accepted and in the FOLLOWING ORDER:\n./AAT number-of-artifacts number-of-jumps";
            break;
        case OPEN_FILE_ERROR:
            errorMessage = "Unable to open file " + fileName;
            break;
        case FILE_FORMAT_ERROR:
            errorMessage = "The format of " + fileName + " file is incorrect.";
            break;
        case ARTIFACT_INPUT_ERROR:
            errorMessage = "The input of artifact is incorrect. It must be an integer in the range 1 to 5 inclusive";
            break;
        case JUMP_INPUT_ERROR:
            errorMessage = "The input of jump is incorrect. It must be an integer in the range 1 to 10 inclusive";
            break;
        default:
            errorMessage = "Error!";
            break;
    }

    std::cerr << errorMessage << std::endl;
    std::exit(1);
}
