#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
    fp = fopen("data.txt", "r");
    if(fp == NULL){
        printf("Error opening file\n");
        return 1;
    }
    int size = 0;
    int arr[MAXSIZE];
    fgets(buffer, MAXSIZE, fp);
    char* token = strtok(buffer, ",");
    while(token != NULL){
        arr[size++] = atoi(token);
        token = strtok(NULL, ", ");
    }
    fclose(fp);
    quickSort(arr, 0, size-1);
    fp = fopen("./c/output.txt", "w");
    for(int i = 0; i < size; i++){
        fprintf(fp, "%d ", arr[i]);
    }
    fclose(fp);
    return 0;
}
