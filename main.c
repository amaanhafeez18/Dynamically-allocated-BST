
#include <stdio.h>
#include "matrix.h"
#include "stdlib.h"
#include "string.h"

int main() {
    // Create a new Matrix.
    Matrix m = matrix_construction();
    // Read from stdin sequence of integer string pair
    Index1 index1;
    Index2 index2 = 0;
    while (1) {
        // assume string will be at most 100 characters long
        index1 = malloc(sizeof(char) * 100);
        //If Ctrl+D then free and escape the while loop
        // A line is divided into two, one part the number, obtained by scanf and one part obtained by fgets which reads
        // till the end of the line(/n)
        if (scanf("%d ", &index2) > 0 && fgets(index1, 100, stdin) != NULL) {
            // Replace the next line character with \0.
            index1[strlen(index1) - 1] = '\0';
            matrix_set(m, index1, index2, 1);
            free(index1);
        } else {
            free(index1);
            break;
        }

    }

    // Printing the strings in columns with a space of 20 characters between each for alignment
    printf("%-20s%-20s%-20s\n", "Number", "Street Name", "Occurrence");
    // Print the data in the Matrix.
    matrix_list(m);


    // Free all allocated memory spaces for the Matrix and terminate.
    matrix_destruction(m);

    return 0;
}
