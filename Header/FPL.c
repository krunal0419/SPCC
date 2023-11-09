#include <stdio.h>
#include "FPL.h"

int main() {
    printf("Factorial of 5 is %d\n", FACTORIAL(5));
    printf("7 is %sprime\n", IS_PRIME(7) ? "" : "not ");
    printf("2000 is %sleap year\n", IS_LEAP_YEAR(2000) ? "" : "not ");
    return 0;
}
