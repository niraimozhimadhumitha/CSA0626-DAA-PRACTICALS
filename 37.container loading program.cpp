#include <stdio.h>
void containerLoading(int items[], int n, int capacity) {
    int containers = 0;
    int current_weight = 0;
    
    for (int i = 0; i < n; i++) {
        if (current_weight + items[i] <= capacity) {
            if(current_weight != 0) {
                printf(" ");
            }
            printf("%d", items[i]);
            current_weight += items[i];
        } else {
            containers++;
            current_weight = items[i];
            printf("\n%d", items[i]);
        }
    }
    printf("\nTotal number of containers needed: %d\n", containers + 1);
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int items[n]; 
    printf("Enter the weights of the items: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &items[i]);

    int capacity; 
    printf("Enter the maximum weight capacity of the containers: ");
    scanf("%d", &capacity);

    containerLoading(items, n, capacity);

    return 0;
}
