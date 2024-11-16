#include <stdio.h>
#include "customDLL.h"

int main(){
    int value;

    input(&value);

    printf("Value: %d", value);

    return 0;
}