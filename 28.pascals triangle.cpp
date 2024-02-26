#include <stdio.h>

int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int binomialCoeff(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {
    int numRows, i, j;

    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &numRows);

    for (i = 0; i < numRows; i++) {
        // Print spaces
        for (j = 0; j < numRows - i - 1; j++) {
            printf(" ");
        }
        for (j = 0; j <= i; j++) {
            printf("%d ", binomialCoeff(i, j));
        }
        printf("\n");
    }

    return 0;
}
