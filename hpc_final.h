/**
 * @file hpc_final.h
 * @brief Header file defining the main data structures and functions.
 * 
 * Contains the declaration of `struct ab` and key functions for memory
 * initialization, memory cleanup, and processing.
 */

#ifndef HPC_FINAL_H
#define HPC_FINAL_H

#include <stdlib.h>

/**
 * @struct ab
 * @brief Represents two flattened 1D arrays used in processing.
 * 
 * This structure holds two dynamically allocated integer arrays `a` and `b`.
 */
struct ab {
    int* a; /**< Pointer to the first array. */
    int* b; /**< Pointer to the second array. */
};

/**
 * @brief Processes data using nested loops and accumulates a result.
 * 
 * @param s Structure containing arrays `a` and `b`.
 * @param w Outer loop count.
 * @param x Middle loop count.
 * @param y Inner loop count.
 * @param z Innermost loop count.
 * @return The accumulated result as a 64-bit integer.
 */
long long int process(struct ab s, int w, int x, int y, int z);

/**
 * @brief Initializes the arrays in the structure `ab`.
 * 
 * Allocates memory for arrays `a` and `b` and initializes them to zero.
 * 
 * @param s Pointer to the structure to initialize.
 * @param size Total size of arrays to allocate.
 */
void initialize(struct ab* s, int size);

/**
 * @brief Frees the dynamically allocated memory in the structure `ab`.
 * 
 * Releases the memory allocated for arrays `a` and `b`.
 * 
 * @param s Pointer to the structure to clean up.
 */
void free_memory(struct ab* s);

#endif // HPC_FINAL_H
