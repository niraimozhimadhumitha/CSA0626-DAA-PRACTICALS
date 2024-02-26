#include <stdio.h>
void insertNumber(int list[], int *size, int number, int position) {
    if (position < 0 || position > *size) {
        printf("Invalid position for insertion\n");
        return;
    }
    for (int i = *size; i > position; i--) {
        list[i] = list[i - 1];
    }
    list[position] = number;
    (*size)++;
}
int main() {
    int list[100], size, number, position;
    printf("Enter the size of the list: ");
    scanf("%d", &size);
    printf("Enter the elements of the list: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }
    printf("Enter the number to insert: ");
    scanf("%d", &number);
    printf("Enter the position to insert: ");
    scanf("%d", &position);
    insertNumber(list, &size, number, position);
    printf("Updated list after insertion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
   return 0;
}
