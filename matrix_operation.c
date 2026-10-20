
#include <stdio.h>

#define MAX 10

// Function to input a matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function for matrix addition
void addMatrices(int A[MAX][MAX], int B[MAX][MAX],
                 int result[MAX][MAX], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function for matrix multiplication
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX],
                      int result[MAX][MAX],
                      int r1, int c1, int c2) {
    int i, j, k;

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            result[i][j] = 0;

            for (k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function for matrix transpose
void transposeMatrix(int A[MAX][MAX],
                     int result[MAX][MAX],
                     int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[j][i] = A[i][j];
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int rows, cols, r1, c1, r2, c2;
    int choice;

    do {
        printf("\n===== MATRIX OPERATIONS =====\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of rows and columns: ");
                scanf("%d %d", &rows, &cols);

                if (rows < 1 || rows > MAX ||
                    cols < 1 || cols > MAX) {
                    printf("Invalid matrix size!\n");
                    break;
                }

                printf("Enter elements of Matrix A:\n");
                inputMatrix(A, rows, cols);

                printf("Enter elements of Matrix B:\n");
                inputMatrix(B, rows, cols);

                addMatrices(A, B, result, rows, cols);

                printf("Result of Addition:\n");
                displayMatrix(result, rows, cols);
                break;

            case 2:
                printf("Enter rows and columns of Matrix A: ");
                scanf("%d %d", &r1, &c1);

                printf("Enter rows and columns of Matrix B: ");
                scanf("%d %d", &r2, &c2);

                if (r1 < 1 || r1 > MAX ||
                    c1 < 1 || c1 > MAX ||
                    r2 < 1 || r2 > MAX ||
                    c2 < 1 || c2 > MAX) {
                    printf("Invalid matrix size!\n");
                    break;
                }

                if (c1 != r2) {
                    printf("Multiplication is not possible!\n");
                    break;
                }

                printf("Enter elements of Matrix A:\n");
                inputMatrix(A, r1, c1);

                printf("Enter elements of Matrix B:\n");
                inputMatrix(B, r2, c2);

                multiplyMatrices(A, B, result, r1, c1, c2);

                printf("Result of Multiplication:\n");
                displayMatrix(result, r1, c2);
                break;

            case 3:
                printf("Enter number of rows and columns: ");
                scanf("%d %d", &rows, &cols);

                if (rows < 1 || rows > MAX ||
                    cols < 1 || cols > MAX) {
                    printf("Invalid matrix size!\n");
                    break;
                }

                printf("Enter elements of Matrix A:\n");
                inputMatrix(A, rows, cols);

                transposeMatrix(A, result, rows, cols);

                printf("Transpose of Matrix A:\n");
                displayMatrix(result, cols, rows);
                break;

            case 4:
                printf("Program exited successfully.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
