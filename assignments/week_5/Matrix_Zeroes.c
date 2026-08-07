#include <stdio.h>
#include <stdbool.h>

int main() {
    int row, col;

    printf("Enter row : ");
    scanf("%d", &row);

    printf("Enter col : ");
    scanf("%d", &col);

    int arr[row][col];

    printf("Enter matrix elements:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    bool first_row = false;
    bool first_col = false;

    // Check first row
    for (int j = 0; j < col; j++) {
        if (arr[0][j] == 0) {
            first_row = true;
            break;
        }
    }

    // Check first column
    for (int i = 0; i < row; i++) {
        if (arr[i][0] == 0) {
            first_col = true;
            break;
        }
    }

    // Mark rows and columns
    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            if (arr[i][j] == 0) {
                arr[i][0] = 0;
                arr[0][j] = 0;
            }
        }
    }

    // Set elements to zero
    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            if (arr[i][0] == 0 || arr[0][j] == 0) {
                arr[i][j] = 0;
            }
        }
    }

    // Zero first row if needed
    if (first_row) {
        for (int j = 0; j < col; j++) {
            arr[0][j] = 0;
        }
    }

    // Zero first column if needed
    if (first_col) {
        for (int i = 0; i < row; i++) {
            arr[i][0] = 0;
        }
    }

    printf("\nMatrix after setZeroes:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
