#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 1000000

void allocate_memory() {
    int* array = (int*) malloc(sizeof(int) * ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand();
    }

    free(array);
}

int main() {
    for (int i = 0; i < 10; i++) {
        allocate_memory();
    }

    printf("Forcing garbage collection...\n");
    malloc(1);

    printf("Allocating memory again...\n");
    allocate_memory();

    return 0;
}
