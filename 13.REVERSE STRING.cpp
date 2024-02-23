#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printReverse(char *str, int index) {
    if (index < 0) {
        return;
    }
    printf("%c", str[index]);
    printReverse(str, index - 1);
}

int main() {
    char inputString[100];
    printf("Enter a string: ");
    fgets(inputString, 100, stdin);
    if (inputString[strlen(inputString) - 1] == '\n') {
        inputString[strlen(inputString) - 1] = '\0';
    }
    printf("Reverse of the string: ");
    printReverse(inputString, strlen(inputString) - 1);
    printf("\n");

    return 0;
}

