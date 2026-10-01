#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_realloc(void *ptr, size_t old_size, size_t new_size) {
    void *new_ptr = malloc(new_size);

    if (new_ptr == NULL) {
        return NULL;
    }

    if (old_size < new_size) {
        memcpy(new_ptr, ptr, old_size);
    }
    else {
        memcpy(new_ptr, ptr, new_size);
    }

    free(ptr);

    return new_ptr;
}

int main() {
    int *arr;
    int initial_size = 5;
    int new_size = 3;
    
    arr = (int *) malloc(initial_size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d integers: ", initial_size);
    for (int i = 0; i < initial_size; i++) {
        scanf("%d", &arr[i]);
    }

    int *new_arr = (int *) my_realloc(arr, initial_size * sizeof(int), new_size * sizeof(int));

    if (new_arr == NULL) {
        printf("Memory reallocation failed!\n");
        free(arr);
        return 1;
    }

    printf("Array after resizing: ");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", new_arr[i]);
    }
    printf("\n");

    free(new_arr);

    return 0;
}
