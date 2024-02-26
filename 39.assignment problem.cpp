#include <stdio.h>

#define MAX 10

void assignJobs(int costMatrix[MAX][MAX], int n, int assignedJobs[MAX]);
void printAssignment(int assignedJobs[MAX], int n);

int main() {
    int n, costMatrix[MAX][MAX], assignedJobs[MAX];

    printf("Enter the number of jobs/workers: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    assignJobs(costMatrix, n, assignedJobs);
    printf("Assigned jobs/workers:\n");
    printAssignment(assignedJobs, n);

    return 0;
}

void assignJobs(int costMatrix[MAX][MAX], int n, int assignedJobs[MAX]) {
    int minCost, minIndex;

    for (int i = 0; i < n; i++) {
        minCost = costMatrix[i][0];
        minIndex = 0;
        for (int j = 1; j < n; j++) {
            if (costMatrix[i][j] < minCost) {
                minCost = costMatrix[i][j];
                minIndex = j;
            }
        }
        assignedJobs[i] = minIndex;
    }
}

void printAssignment(int assignedJobs[MAX], int n) {
    for (int i = 0; i < n; i++) {
        printf("Worker %d is assigned to Job %d\n", i + 1, assignedJobs[i] + 1);
    }
}
