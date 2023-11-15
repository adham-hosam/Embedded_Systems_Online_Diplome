#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "RandomValue.h"

static unsigned long long int lcg_seed = 0;

unsigned long long int generateRandomValue() {
    // LCG parameters
    unsigned long long int m = 4294967296;  // Modulus
    unsigned long long int a = 1664525;     // Multiplier
    unsigned long long int c = 1013904223;  // Increment

    if (lcg_seed == 0) {
        // Initialize the seed only once
        lcg_seed = (unsigned long long int)time(NULL);
    }
    lcg_seed = (a * lcg_seed + c) % m;  // Generate next value using LCG formula

    return lcg_seed;
}

int generateRandomDistance(int minValue, int maxValue) {
    unsigned long long int randomValue = generateRandomValue();
    int range = maxValue - minValue + 1;
    int scaledValue = (int)(randomValue % range) + minValue;

    return scaledValue;
}
