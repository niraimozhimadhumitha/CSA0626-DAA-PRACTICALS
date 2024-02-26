#include <stdio.h>
int binomialCoefficient(int n, int k) {
    int C[n + 1][k + 1];
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= i && j <= k; j++) {
                if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][k];
}
int main() {
    int n, k;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");ev
    scanf("%d", &k);
    if (k > n) {
        printf("Invalid input: k should be less than or equal to n\n");
        return 1;
    }
    printf("Binomial coefficient C(%d, %d) is: %d\n", n, k, binomialCoefficient(n, k));
    return 0;
}
