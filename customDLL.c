#include <stdio.h>
#include "customDLL.h"

__declspec(dllexport) int intIn(int *target){
    char buffer[999];
    int correct = 1;
    int value;

    if (fgets(buffer, sizeof(buffer), stdin) != 0){
        for (int i = 0; i < sizeof(buffer); i++){
            if (buffer[i] == '\0' || buffer[i] == '\n'){
                break;
            }

            if ((buffer[i] > '9' || buffer[i] < '0') && correct == 1){
                fprintf(stderr, "Error: Char %c", buffer[i]);
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
asdjklasdjsaklsdsajdkl
