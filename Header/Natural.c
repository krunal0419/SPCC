#include <stdio.h>
#include "Natural.h"

int main() {
    int n = 3 , x = 10;
    int factorial = fact(n);
    int sum = Natural(x);
    printf("Factorial of %d is %d\n", n, factorial);
    printf("Sum of natural numbers till %d is %d\n", x, sum);
    return 0;
}
