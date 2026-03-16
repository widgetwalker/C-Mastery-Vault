#include <stdio.h>
int binarySearch(int array[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (array[mid] == x)
            return mid;
        if (array[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main() {
    int array[] = {2, 4, 0, 1, 9};
    int x = 1;
    int n = sizeof(array) / sizeof(array[0]);

    int result = binarySearch(array, n, x);

    (result == -1) ? printf("Element not found") : printf("Element found at index: %d", result);

    return 0;
}
