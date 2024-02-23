#include <stdio.h>
#include <stdlib.h>

// Structure to represent each item
struct Item {
    int value;
    int weight;
};

// Function to perform a comparison for sorting based on value-to-weight ratio
int compare(const void *a, const void *b) {
    double ratioA = (double)(((struct Item *)a)->value) / (((struct Item *)a)->weight);
    double ratioB = (double)(((struct Item *)b)->value) / (((struct Item *)b)->weight);
    if (ratioA < ratioB)
        return 1; // Sort in descending order
    else if (ratioA > ratioB)
        return -1;
    else
        return 0;
}

// Function to solve fractional knapsack problem
double fractionalKnapsack(int W, struct Item items[], int n) {
    // Sort items by value-to-weight ratio
    qsort(items, n, sizeof(struct Item), compare);
    
    int currentWeight = 0;  // Current weight in knapsack
    double finalValue = 0.0; // Final value of items in knapsack

    // Iterate through all items
    for (int i = 0; i < n; i++) {
        // If adding the whole item doesn't overflow the knapsack
        if (currentWeight + items[i].weight <= W) {
            // Add the whole item
            currentWeight += items[i].weight;
            finalValue += items[i].value;
        } else {
            // Add fractional part of the item
            int remainingWeight = W - currentWeight;
            finalValue += items[i].value * ((double)remainingWeight / items[i].weight);
            break; // Knapsack is full
        }
    }
    return finalValue;
}

int main() {
    int W; // Capacity of knapsack
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &W);

    int n; // Number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item *items = malloc(n * sizeof(struct Item));
    if (items == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Input each item's value and weight
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    double result = fractionalKnapsack(W, items, n);
    printf("The maximum value in knapsack is: %.2f\n", result);

    // Free dynamically allocated memory
    free(items);

    return 0;
}

