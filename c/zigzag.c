#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    if (numRows == 1) return s;

    int n = strlen(s);
    char* result = (char*)malloc((n + 1) * sizeof(char));
    char** rows = (char**)malloc(numRows * sizeof(char*));
    int* rowSizes = (int*)calloc(numRows, sizeof(int));
    for (int i = 0; i < numRows; i++) {
        rows[i] = (char*)malloc((n + 1) * sizeof(char));
    }

    int currentRow = 0;
    int goingDown = 0; 

    for (int i = 0; i < n; i++) {
        rows[currentRow][rowSizes[currentRow]++] = s[i];
        if (currentRow == 0 || currentRow == numRows - 1) {
            goingDown = !goingDown;
        }
        currentRow += goingDown ? 1 : -1;
    }
    int k = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < rowSizes[i]; j++) {
            result[k++] = rows[i][j];
        }
        free(rows[i]);
    }
    result[k] = '\0';
    free(rows);
    free(rowSizes);

    return result;
}
