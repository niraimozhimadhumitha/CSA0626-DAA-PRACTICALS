#include <stdio.h>
int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, left, mid - 1, x);
        return binarySearch(arr, mid + 1, right, x);
    }
    return -1;
}

int main() {
    int arr[100], n, x, result;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    printf("Enter %d integers in ascending order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &x);
    result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        printf("Element not present in array\n");
    else
        printf("Element found at index %d\n", result);

    return 0;
}

