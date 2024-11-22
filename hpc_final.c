/**
 * @file hpc_final.c
 * @brief Implementation of functions declared in `hpc_final.h`.
 * 
 * Contains the function definitions for initializing, freeing, and processing
 * the data stored in `struct ab`.
 */

#include "hpc_final.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Initializes the arrays in the structure `ab`.
 * 
 * Allocates memory for arrays `a` and `b` and sets all elements to zero.
 * 
 * @param s Pointer to the structure to initialize.
 * @param size Total size of arrays to allocate.
 */
void initialize(struct ab* s, int size) {
    s->a = malloc(size * sizeof(int));
    s->b = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        s->a[i] = 0;
        s->b[i] = 0;
    }
}

/**
 * @brief Frees the dynamically allocated memory in the structure `ab`.
 * 
 * Releases the memory allocated for arrays `a` and `b`.
 * 
 * @param s Pointer to the structure to clean up.
 */
void free_memory(struct ab* s) {
    free(s->a);
    free(s->b);
}

/**
 * @brief Processes data using nested loops and accumulates a result.
 * 
 * Modifies elements in the array `a` using random numbers and computes
 * values for `b` based on the sum of adjacent elements in `a`. The result
 * is the sum of all elements in `b`.
 * 
 * @param s Structure containing arrays `a` and `b`.
 * @param w Outer loop count.
 * @param x Middle loop count.
 * @param y Inner loop count.
 * @param z Innermost loop count.
 * @return The accumulated result as a 64-bit integer.
 */
long long int process(struct ab s, int w, int x, int y, int z) {
    long long int t = 0;
    int* a_pointer = s.a;
    int* b_pointer = s.b;
    srand(1234);

    for (int h = 0; h < w; h++) {
        for (int k = 0; k < x; k++) {
            int base_k = k * y * z;
            for (int j = 0; j < y; j++) {
                int base_j = base_k + j * z;
                int* current_a = a_pointer + base_j;
                for (int i = 0; i < z; i++) {
                    *current_a += rand() % 3;
                    current_a++;
                }
            }
        }

        for (int k = 0; k < x; k++) {
            int base_k = k * y * z;
            for (int j = 1; j < y; j++) {
                int base_j = base_k + j * z;
                int prev_j = base_j - z;
                int* current_a = a_pointer + base_j;
                int* previous_a = a_pointer + prev_j;
                int* current_b = b_pointer + base_j;
                for (int i = 0; i < z; i++) {
                    *current_b = *current_a + *previous_a;
                    t += *current_b;
                    current_a++;
                    previous_a++;
                    current_b++;
                }
            }
        }
    }

    return t;
}
