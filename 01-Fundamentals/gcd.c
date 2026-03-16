#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int n, i;
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    int numbers[n];
    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &numbers[i]);

    int result = numbers[0];
    for (i = 1; i < n; i++)
        result = gcd(result, numbers[i]);

    printf("GCD of the %d numbers is: %d\n", n, result);

    return 0;
}
