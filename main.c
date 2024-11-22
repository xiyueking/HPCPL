/**
 * @file main.c
 * @brief Entry point for the program.
 * 
 * Demonstrates the usage of `hpc_final.h` by initializing arrays, processing
 * data, and cleaning up memory.
 */

#include <stdio.h>
#include <stdlib.h>
#include "hpc_final.h"

int main() {
    int w = 50, x = 100, y = 200, z = 300;
    struct ab s;
    int total_size = x * y * z;

    // Initialize struct ab
    initialize(&s, total_size);

    // Execute processing function
    long long int result = process(s, w, x, y, z);

    // Output the result
    printf("%lld\n", result);

    // Free memory
    free_memory(&s);

    return 0;
}
