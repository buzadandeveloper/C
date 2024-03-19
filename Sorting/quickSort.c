#include<stdio.h>
#include<stdlib.h>
#include <time.h>
void memory(int ***arr, int **arr2, int n);
void freeMemory(int **arr, int *arr2, int n);
void fillRandom(int **arr, int n);
void output(int **arr, int n);
void output1D(int *arr2, int h);
void takeColumn(int **arr, int *arr2, int n, int *h);
void swap(int *x, int *y);
int partition(int *arr2, int start, int end);
void quickSort(int *arr2, int start, int end);
int main(){
    int **arr = NULL, *arr2 = NULL, n, h;
    printf("Introduceti dimensiunea arr:");
    scanf("%d", &n);
    memory(&arr, &arr2, n);
    fillRandom(arr, n);
    output(arr, n);
    takeColumn(arr, arr2, n, &h);
    printf("\n");
    output1D(arr2, h);
    quickSort(arr2, 0, n - 1);
    printf("\n");
    output1D(arr2, n);
    freeMemory(arr,arr2,n);
    return 0;
}
void memory(int ***arr, int **arr2, int n){
    *arr = (int **) malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++){
        (*arr)[i] = (int*) calloc(n, sizeof (int));
        if((*arr)[i] == NULL){
            printf("Eroare la alocare!");
            exit(1);
        }
    }
    *arr2 = (int*) calloc(n * n, sizeof (int));
    if(*arr2 == NULL){
        printf("Eroare la alocare!");
        exit(1);
    }
}
void freeMemory(int **arr, int *arr2, int n){
    for(int i = 0; i < n; i++){
        free(*(arr + i));//arr[i]
    }
    free(arr);
    free(arr2);
}
void fillRandom(int **arr, int n){
    srand(time(0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            *(*(arr + i) + j) = rand()%10;
        }
    }
}
void output(int **arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
}
void output1D(int *arr2, int h){
    for(int i = 0; i < h; i++){
        printf("%d ", *(arr2 + i));
    }
}
void takeColumn(int **arr, int *arr2, int n, int *h){
    *h = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                arr2[(*h)++] = *(*(arr + i) + j);
            }
        }
    }
}
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int *arr2, int start, int end){
    int pivot = arr2[end];
    int i = start;

    for(int j = start; j < end; j++){
        if(arr2[j] < pivot){
            swap(arr2 + i, arr2 + j);
            i++;
        }
    }
    swap(arr2 + i, arr2 + end);
    return i;
}
void quickSort(int *arr2, int start, int end){
    int piv_index;
    if(start < end){
        piv_index = partition(arr2, start, end);
        quickSort(arr2, start, piv_index - 1);
        quickSort(arr2, piv_index + 1, end);
    }
}
