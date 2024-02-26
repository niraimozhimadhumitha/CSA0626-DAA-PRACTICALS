#include <stdio.h>
#include <stdlib.h>

#define MAX_CITIES 10
#define INF 999999

int min(int a, int b) {
    return (a < b) ? a : b;
}
int tsp(int n, int graph[MAX_CITIES][MAX_CITIES], int start) {
    int i, j, k;
    int subset, temp;
    int dp[1 << MAX_CITIES][MAX_CITIES];
    for (i = 0; i < (1 << n); i++) {
        for (j = 0; j < n; j++) {
            dp[i][j] = INF;
        }
    }
    for (i = 0; i < n; i++) {
        dp[1 << i][i] = graph[start][i];
    }
    for (subset = 1; subset < (1 << n); subset++) {
        for (i = 0; i < n; i++) {
            if (!(subset & (1 << i))) continue;
            for (j = 0; j < n; j++) {
                if (i == j || !(subset & (1 << j))) continue;
                dp[subset][i] = min(dp[subset][i], dp[subset ^ (1 << i)][j] + graph[j][i]);
            }
        }
    }

    int final_subset = (1 << n) - 1;
    int min_cost = INF;
    for (i = 0; i < n; i++) {
        if (i != start) {
            min_cost = min(min_cost, dp[final_subset][i] + graph[i][start]);
        }
    }

    return min_cost;
}

int main() {
    int n, i, j;
    int graph[MAX_CITIES][MAX_CITIES];

    printf("Enter the number of cities (max %d): ", MAX_CITIES);
    scanf("%d", &n);

    if (n > MAX_CITIES || n <= 0) {
        printf("Number of cities must be between 1 and %d\n", MAX_CITIES);
        return 1;
    }

    printf("Enter the distances between each pair of cities:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Distance from city %d to city %d: ", i + 1, j + 1);
            scanf("%d", &graph[i][j]);
        }
    }

    int start_city;
    printf("Enter the starting city (1 to %d): ", n);
    scanf("%d", &start_city);
    start_city--;

    int min_cost = tsp(n, graph, start_city);

    printf("Minimum cost of TSP: %d\n", min_cost);

    return 0;
}
