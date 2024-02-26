#include <stdio.h>
#define MAX 10
#define INF 999

int graph[MAX][MAX];
int visited[MAX];
int numVertices;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int currentVertex, int count, int cost) {
    if (count == numVertices && currentVertex == 0) {
        return cost;
    }

    int minCost = INF;
int i;
    for (i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            minCost = min(minCost, tsp(i, count + 1, cost + graph[currentVertex][i]));
            visited[i] = 0;
        }
    }

    return minCost;
}

int main() {
    printf("Enter the number of vertices (maximum 10): ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix for the graph:\n");
int i,j;
    for (i = 0; i < numVertices; i++) {
        for ( j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
        visited[i] = 0;
    }

    visited[0] = 1; 

    int optimalCost = tsp(0, 1, 0);

    printf("Optimal Cost for TSP: %d\n", optimalCost);

    return 0;
}
