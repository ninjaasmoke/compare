#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main(){
    FILE *fp;
    int val;
    int size = 0;
    int capacity = 0;
    int* arr = NULL;

    fp = fopen("data.txt", "r");
    if(fp == NULL){
        printf("Error: Could not open file for reading\n");
        return 1;
    }

    while(fscanf(fp, "%d,", &val) == 1){
        if (size == capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            arr = realloc(arr, capacity * sizeof(int));
            if (arr == NULL) {
                printf("Error: Could not allocate memory\n");
                return 1;
            }
        }
        arr[size++] = val;
    }
    fclose(fp);

    quickSort(arr, 0, size-1);

    fp = fopen("./output/c.txt", "w");
    if(fp == NULL){
        printf("Error: Could not open file for writing\n");
        free(arr);
        return 1;
    }

    for(int i = 0; i < size; i++){
        fprintf(fp, "%d ", arr[i]);
    }

    fclose(fp);
    free(arr);
    return 0;
}
