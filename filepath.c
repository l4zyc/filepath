#include <stdio.h>
#include <stdlib.h>

int main() {
    char filepath[] = "town.txt";
    FILE *fptr = fopen(filepath, "r");
    if (fptr == NULL) {
        printf("File Not Found\n");
        return 1;
    }

    char ch;
    int rows = 0;
    int maxCols = 0;
    int currentCols = 0;

    while ((ch = fgetc(fptr)) != EOF) {
        if (ch == '\n') {
            rows++;
            if (currentCols > maxCols) {
                maxCols = currentCols;
            }
            currentCols = 0; 
        } else {
            currentCols++;
        }
    }

    if (currentCols > maxCols) {
        maxCols = currentCols;
    }
    rows++;

    rewind(fptr);

    char **map = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        map[i] = (char *)malloc((maxCols + 1) * sizeof(char));
        for (int j = 0; j < maxCols; j++) {
            map[i][j] = ' ';
        }
        map[i][maxCols] = '\0';
    }

    int row = 0, col = 0;
    while ((ch = fgetc(fptr)) != EOF) {
        if (ch == '\n') {
            row++;
            col = 0;
        } else {
            map[row][col++] = ch;
        }
    }

    fclose(fptr);

    for (int i = 0; i < rows; i++) {
        for(int j = 0; j < maxCols; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}
