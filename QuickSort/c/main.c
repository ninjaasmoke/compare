#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1000000

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
    char buffer[MAXSIZE];
    int size = 0;

    // Open file for reading
    fp = fopen("data.txt", "r");
    if(fp == NULL){
        printf("Error: Could not open file for reading\n");
        return 1;
    }

    // Read integers from file into array
    int* arr = malloc(MAXSIZE * sizeof(int));
    if (arr == NULL) {
        printf("Error: Could not allocate memory\n");
        return 1;
    }
    fgets(buffer, MAXSIZE, fp);
    char* token = strtok(buffer, ",");
    while(token != NULL){
        int val = atoi(token);
        arr[size] = val;
        size++;
        token = strtok(NULL, ", ");
    }
    fclose(fp);

    // Sort array
    quickSort(arr, 0, size-1);

    // Open file for writing
    fp = fopen("./c/output.txt", "w");
    if(fp == NULL){
        printf("Error: Could not open file for writing\n");
        free(arr);
        return 1;
    }

    // Write sorted array to file
    for(int i = 0; i < size; i++){
        fprintf(fp, "%d ", arr[i]);
    }

    // Clean up and exit
    fclose(fp);
    free(arr);
    return 0;
}
