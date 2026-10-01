#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n;
    double avg;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    while(n <= 0) {
        printf("Number of elements has to be a positive number!\n");
        printf("Enter the number of elements: ");
        scanf("%d", &n);
    }

    arr = (int *) calloc(n, sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Array after calloc: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nEnter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Updated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    for (int i = 0; i < n; i++) {
        avg += arr[i];
    }
    avg /= n;
    printf("\nAverage of the array: %f\n", avg);

    free(arr);

    return 0;
}

