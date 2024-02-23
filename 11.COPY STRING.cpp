#include <stdio.h>
#include <stdlib.h>
void copyString(char *source, char *destination, int index) {
    if (source[index] == '\0') {
        destination[index] = '\0';
        return;
    }
    destination[index] = source[index];
    copyString(source, destination, index + 1);
}

int main() {
    char sourceString[100];
    char destinationString[100];
    printf("Enter the source string: ");
    fgets(sourceString, 100, stdin);
    copyString(sourceString, destinationString, 0);
    printf("Copied string: %s\n", destinationString);

    return 0;
}

