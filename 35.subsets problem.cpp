#include <stdio.h>
#define MAX 100
int set[MAX], subset[MAX];
int n, sum, count;
void findSubsets(int pos, int curSum, int remainingSum) {
    if (curSum == sum) {
        printf("Subset %d: ", ++count);
        for (int i = 0; i < pos; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }
    if (curSum > sum || remainingSum + curSum < sum) {
        return;
    }
    for (int i = pos; i < n; i++) {
        subset[pos] = set[i];
        findSubsets(pos + 1, curSum + set[i], remainingSum - set[i]);
    }
}
int main() {
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &sum);
    count = 0;
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += set[i];
    }
    findSubsets(0, 0, totalSum);
        if (count == 0) {
        printf("No subset found with the given sum.\n");
    }
    return 0;
}
