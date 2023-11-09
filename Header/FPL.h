#define FACTORIAL(n) \
    ({ \
        int result = 1; \
        for (int i = 1; i <= (n); ++i) { \
            result *= i; \
        } \
        result; \
    })

#define IS_PRIME(n) \
    ({ \
        int is_prime = 1; \
        for (int i = 2; i * i <= (n); ++i) { \
            if ((n) % i == 0) { \
                is_prime = 0; \
                break; \
            } \
        } \
        is_prime; \
    })

#define IS_LEAP_YEAR(year) (((year) % 4 == 0 && (year) % 100 != 0) || (year) % 400 == 0)