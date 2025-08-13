/* keygen.c
 * Author: Jeffrey Hughes
 * CS 374 Operating Systems, Summer 2025
 * Generates a key file of specified length with random uppercase letters and spaces
 * Based on Assignment 4 instructions and K&R Ch. 7.8 for rand usage
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h> // getpid for seed

int main(int argc, char *argv[]) {
    // Check usage & args
    if (argc != 2) {
        fprintf(stderr, "Usage: %s keylength\n", argv[0]);
        exit(1);
    }
    int keylen = atoi(argv[1]);
    if (keylen <= 0) {
        fprintf(stderr, "Error: keylength must be positive integer\n");
        exit(1);
    }

    // Seed rand with time and pid for varity (K&R 2.7 time basics)
    srand(time(NULL) ^ getpid());

    // Allowed chars: A-Z and space
    const char allowed[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

    // Output random chars
    for (int i = 0; i < keylen; i++) {
        putchar(allowed[rand() % 27]);
    }
    putchar('\n');  // End with newline per assignment guidelines


    return 0;
    
}