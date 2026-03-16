#include <stdio.h>
int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main() {
    int n, i, search, result;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value to find: ");
    scanf("%d", &search);
    result = binarySearch(arr, 0, n - 1, search);
    if (result == -1)
        printf("Element not found!\n");
    else
        printf("Element found at index %d\n", result + 1);
    return 0;
}
