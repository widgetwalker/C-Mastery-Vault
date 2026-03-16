#include <stdio.h>

int linearSearch(int array[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (array[i] == x)
            return i;
    return -1;
}
int main() {
    int n, x, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    printf("Enter the target value: ");
    scanf("%d", &x);

    int result = linearSearch(array, n, x);

    (result == -1) ? printf("Element not found") : printf("Element found at index: %d", result);

    return 0;
}
