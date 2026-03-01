#include <stdio.h>

#define MAX 10

// Function to input matrix
void inputMatrix(int matrix[MAX][MAX], int r, int c) {
    int i, j;
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display matrix
void displayMatrix(int matrix[MAX][MAX], int r, int c) {
    int i, j;
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Matrix Addition
void addMatrix(int A[MAX][MAX], int B[MAX][MAX], int r, int c) {
    int C[MAX][MAX];
    int i, j;

    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            C[i][j] = A[i][j] + B[i][j];

    printf("\nAddition Result:\n");
    displayMatrix(C, r, c);
}

// Matrix Multiplication
void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX], int r1, int c1, int c2) {
    int C[MAX][MAX] = {0};
    int i, j, k;

    for(i = 0; i < r1; i++)
        for(j = 0; j < c2; j++)
            for(k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];

    printf("\nMultiplication Result:\n");
    displayMatrix(C, r1, c2);
}

// Matrix Transpose
void transposeMatrix(int A[MAX][MAX], int r, int c) {
    int T[MAX][MAX];
    int i, j;

    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            T[j][i] = A[i][j];

    printf("\nTranspose Matrix:\n");
    displayMatrix(T, c, r);
}

int main() {
    int A[MAX][MAX], B[MAX][MAX];
    int r1, c1, r2, c2;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter elements of Matrix A:\n");
    inputMatrix(A, r1, c1);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    printf("Enter elements of Matrix B:\n");
    inputMatrix(B, r2, c2);

    if(r1 == r2 && c1 == c2)
        addMatrix(A, B, r1, c1);
    else
        printf("\nAddition not possible\n");

    if(c1 == r2)
        multiplyMatrix(A, B, r1, c1, c2);
    else
        printf("\nMultiplication not possible\n");

    transposeMatrix(A, r1, c1);

    return 0;
}