#include <stdio.h>
#include "customDLL.h"

#define input(target) _Generic((target), int*: inputInt, float*: inputFloat, default: defaultError)(target)

__declspec(dllexport) int inputInt(int* target){
    char buffer[999];
    char tempVar;
    int correct = 1;
    int value;

    if (fgets(buffer, sizeof(buffer), stdin) != 0){
        for (int i = 0; i < sizeof(buffer); i++){
            tempVar = buffer[i];

            if (tempVar == '\0' || tempVar == '\n'){
                break;
            }

            if (i == 0 && tempVar == '-'){
                continue;
            }

            if ((tempVar > '9' || tempVar < '0') && correct == 1){
                fprintf(stderr, "Error: Char %c\n", buffer[i]);
                correct = 0;
            }
        }

        if (correct == 0) {return 0;}

        sscanf(buffer, "%d", &value);
        *target = value;

        return 1;
    }

    return 0;
}

__declspec(dllexport) int inputChar(char* target){
    char buffer[3];

    if (fgets(buffer, sizeof(buffer), stdin) != 0){
        *target = buffer[0];
        return 1;
    }

    return 0;
}

__declspec(dllexport) int inputFloat(float* target){
    char buffer[999];
    char tempVar;
    int correct = 1;
    float value;

    if (fgets(buffer, sizeof(buffer), stdin) != 0){
        for (int i = 0; i < sizeof(buffer); i++){
            tempVar = buffer[i];

            if (tempVar == '\0' || tempVar == '\n'){
                break;
            }

            if (i == 0 && tempVar == '-'){
                continue;
            }

            if ((tempVar > '9' || tempVar < '0') && tempVar != '.' && correct == 1){
                fprintf(stderr, "Error: Char %c\n", buffer[i]);
                correct = 0;
            }
        }

        if (correct == 0) {return 0;}

        sscanf(buffer, "%f", &value);
        *target = value;

        return 1;
    }

    return 0;
}

__declspec(dllexport) int defaultError(void* target){
    fprintf(stderr, "Error: Invalid Type\n");
    return 0;
}