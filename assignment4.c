#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int max_length = 50;
    int initial_size = 3;
    int new_size = initial_size + 2;

    char **arr = malloc(initial_size * sizeof(char *));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < initial_size; i++) {
        arr[i] = malloc((max_length + 1) * sizeof(char));

        if (arr[i] == NULL) {
            printf("Memory allocation failed.\n");

            for (int j = 0; j < i; j++) {
                free(arr[j]);
            }

            free(arr);
            return 1;
        }
    }

    printf("Enter %d strings: ", initial_size);
    for (int i = 0; i < initial_size; i++) {
        scanf("%50s", arr[i]);
    }

    char **new_arr = realloc(arr, new_size * sizeof(char *));

    if (new_arr == NULL) {
        printf("Memory reallocation failed.\n");

        for (int i = 0; i < initial_size; i++) {
            free(arr[i]);
        }

        free(arr);
        return 1;
    }

    for (int i = initial_size; i < new_size; i++) {
        new_arr[i] = malloc((max_length + 1) * sizeof(char));

        if (new_arr[i] == NULL) {
            printf("Memory allocation failed.\n");

            for (int j = 0; j < i; j++) {
                free(new_arr[j]);
            }

            free(new_arr);
            return 1;
        }
    }

    printf("Enter %d more strings: ", (new_size - initial_size));

    for (int i = initial_size; i < new_size; i++) {
        scanf("%50s", new_arr[i]);
    }

    printf("All strings: ");
    for (int i = 0; i < new_size; i++) {
        printf("%s ", new_arr[i]);
    }

    printf("\n");

    for (int i = 0; i < new_size; i++) {
        free(new_arr[i]);
    }

    free(new_arr);

    return 0;
}
