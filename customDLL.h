#ifndef customDLL
#define customDLL

#include <stdio.h>

__declspec(dllexport) int inputInt(int *target);

#define LOG "LOG"
#define ERROR "ERROR"
#define DEBUG "DEBUG"

#define typeOf(data, type) _Generic((data), type: 1, default: 0);

#define errOut(type, message, other) _Generic((other), \
    int:    fprintf(stderr, "%s: %s %d\n", type, message, other), \
    char:   fprintf(stderr, "%s: %s %c\n", type, message, other), \
    float:  fprintf(stderr, "%s: %s %f\n", type, message, other), \
    double: fprintf(stderr, "%s: %s %f\n", type, message, other), \
    default: fprintf(stderr, "%s: %s (unsupported type)\n", type, message) \
);

#endif