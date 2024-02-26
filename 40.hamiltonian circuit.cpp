#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int path[MAX]; 
int graph[MAX][MAX]; 
int V; 

void printSolution() {
    printf("Hamiltonian Circuit: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]); 
}

bool isSafe(int v, int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;
    for (int i = 0; i < pos; i++) {
        if (path[i] == v)
            return false;
    }
    return true;
}

bool hamCycleUtil(int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }
    for (int v = 1; v < V; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v; 
            if (hamCycleUtil(pos + 1) == true)
                return true;
            path[pos] = -1; 
        }
    }
    return false;
}

bool hamCycle(int graph[MAX][MAX], int V) {
    path[0] = 0;
    for (int i = 1; i < V; i++)
        path[i] = -1; 
    if (hamCycleUtil(1) == false) {
        printf("No Hamiltonian Circuit exists.\n");
        return false;
    }
    printSolution();
    return true;
}

int main() {
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);
    printf("Enter the adjacency matrix (0/1) representing the graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    hamCycle(graph, V);
    return 0;
}
