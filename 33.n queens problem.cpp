#include <stdio.h>
#include <stdbool.h>
#define N 10 
int board[N][N];
bool isSafe(int row, int col, int n) {
    int i, j;
        for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
        for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
        for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;
    return true;
}
bool solveNQUtil(int col, int n) {
    if (col >= n)
        return true;
    for (int i = 0; i < n; i++) {
        if (isSafe(i, col, n)) {
            board[i][col] = 1;
            if (solveNQUtil(col + 1, n))
                return true;
            board[i][col] = 0; 
        }
    }
    return false;
}
void solveNQ(int n) {
   	    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;
    if (!solveNQUtil(0, n)) {
        printf("Solution does not exist");
        return;
    }
        for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}
int main() {
    int n;
    printf("Enter the number of Queens: ");
    scanf("%d", &n);
    printf("Board configuration for %d Queens:\n", n);
    solveNQ(n);
    return 0;
}
