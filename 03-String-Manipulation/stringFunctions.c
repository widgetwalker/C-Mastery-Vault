#include <stdio.h>

void myStrcpy(char *dest, const char *src) {
    while ((*dest++ = *src++));
}

int myStrlen(const char *str) {
    int len = 0;
    while (*str++) len++;
    return len;
}

void myStrcat(char *dest, const char *src) {
    while (*dest) dest++; // Move to the end of dest
    myStrcpy(dest, src); // Copy src to the end of dest
}

int myStrcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

char *myStrstr(const char *haystack, const char *needle) {
    if (!*needle) return (char *)haystack; // Empty needle
    for (; *haystack; haystack++) {
        if (*haystack == *needle) {
            const char *h = haystack, *n = needle;
            while (*h && *n && (*h == *n)) {
                h++;
                n++;
            }
            if (!*n) return (char *)haystack; // Found
        }
    }
    return NULL; // Not found
}

int main() {
    char str1[100], str2[100], result[200];
    int choice;

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[myStrlen(str1) - 1] = '\0'; // Remove newline

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[myStrlen(str2) - 1] = '\0'; // Remove newline

    do {
        printf("\nChoose an operation:\n");
        printf("1. Length of first string\n");
        printf("2. Copy second string to first\n");
        printf("3. Concatenate second string to first\n");
        printf("4. Compare strings\n");
        printf("5. Find substring\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1:
                printf("Length of first string: %d\n", myStrlen(str1));
                break;
            case 2:
                myStrcpy(str1, str2);
                printf("First string after copy: %s\n", str1);
                break;
            case 3:
                myStrcat(str1, str2);
                printf("First string after concatenation: %s\n", str1);
                break;
            case 4:
                printf("Comparison result: %d\n", myStrcmp(str1, str2));
                break;
            case 5:
                if (myStrstr(str1, str2))
                    printf("Second string is found in first string.\n");
                else
                    printf("Second string is not found in first string.\n");
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
