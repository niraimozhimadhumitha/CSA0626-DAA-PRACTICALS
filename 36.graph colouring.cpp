#include<stdio.h>
#define V 50
int graph[V][V], color[V];
int isSafe(int v, int c, int n) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && c == color[i])
            return 0;
    }
    return 1;
}
int graphColoringUtil(int v, int m, int n) {
    if (v == n) 
        return 1;
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c, n)) {
            color[v] = c; 
            if (graphColoringUtil(v + 1, m, n) == 1)
                return 1; 
            color[v] = 0; 
        }
    }
    return 0; 
}
void printSolution(int n) {
    printf("Vertex\tColor\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\n", i, color[i]);
}
void graphColoring(int m, int n) {
    if (graphColoringUtil(0, m, n) == 0) {
        printf("Solution does not exist\n");
        return;
    }
    printSolution(n);
}
int main() {
    int n, m; 
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    printf("Enter the number of colors: ");
    scanf("%d", &m);
    graphColoring(m, n);
    return 0;
}
