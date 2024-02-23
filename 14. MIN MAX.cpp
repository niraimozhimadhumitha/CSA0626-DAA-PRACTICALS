#include <stdio.h>
#include <stdlib.h>

void printMinMaxSequence(int *list, int length) {
    int i, minSeq = 0, maxSeq = 0, minSeqStart = 0, maxSeqStart = 0;
    int currMin = list[0], currMax = list[0];

    for (i = 1; i < length; i++) {
        if (list[i] >= list[i - 1]) {
            minSeq++;
            if (minSeq > maxSeq) {
                maxSeq = minSeq;
                maxSeqStart = minSeqStart;
            }
        } else {
            minSeq = 0;
            minSeqStart = i;
        }
        if (list[i] <= list[i - 1]) {
            maxSeq++;
            if (maxSeq > minSeq) {
                minSeq = maxSeq;
                minSeqStart = maxSeqStart;
            }
        } else {
            maxSeq = 0;
            maxSeqStart = i;
        }
    }

    printf("Minimum value sequence starts at index %d with length %d\n", minSeqStart, minSeq + 1);
    printf("Maximum value sequence starts at index %d with length %d\n", maxSeqStart, maxSeq + 1);
}

int main() {
    int length, i;
    
    printf("Enter the length of the list: ");
    scanf("%d", &length);

    int *list = (int*)malloc(length * sizeof(int));

    printf("Enter the numbers in the list:\n");
    for (i = 0; i < length; i++) {
        scanf("%d", &list[i]);
    }

    printMinMaxSequence(list, length);

    free(list);

    return 0;
}

