 #include <stdio.h>
#include <limits.h>
float sum(float freq[], int i, int j) {
    float s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}
float optimalBST(float keys[], float freq[], int n) {
        float cost[n][n];
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L + 1; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;
            for (int r = i; r <= j; r++) {
                float c = ((r > i) ? cost[i][r - 1] : 0) +
                          ((r < j) ? cost[r + 1][j] : 0) +
                          sum(freq, i, j);
                cost[i][j] = (c < cost[i][j]) ? c : cost[i][j];
            }
        }
    }
    return cost[0][n - 1];
}
int main() {
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);
    float keys[n], freq[n];
    printf("Enter the keys and their corresponding probabilities:\n");
    for (int i = 0; i < n; i++) {
        printf("Key %d: ", i + 1);
        scanf("%f", &keys[i]);
        printf("Frequency for Key %d: ", i + 1);
        scanf("%f", &freq[i]);
    }
    printf("Cost of optimal BST is: %.2f\n", optimalBST(keys, freq, n));
    return 0;
}
