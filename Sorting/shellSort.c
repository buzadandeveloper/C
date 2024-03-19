#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void memory(int ***arr, int **arr2, int n);
void freeMemory(int **arr, int *arr2, int n);
void fillRandom(int **arr, int n);
void output(int **arr, int n);
void takeColumn(int **arr, int *arr2, int n, int *h);
void output1D(int *arr2, int h);
void shellSort(int *arr2, int h);
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
    shellSort(arr2, h);
    printf("\n");
    output1D(arr2, h);
    freeMemory(arr, arr2, n);
    return 0;
}
void memory(int ***arr, int **arr2, int n){
    *arr = (int**) malloc(n *sizeof (int*));
    for(int i = 0; i < n; i++){
        (*arr)[i] = (int *) calloc(n, sizeof (int));
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
        free(*(arr + i));
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
void takeColumn(int **arr, int *arr2, int n, int *h){
    *h = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i + j == n - 1){
                arr2[(*h)++] = *(*(arr + i) + j);
            }
        }
    }
}
void output1D(int *arr2, int h){
    for(int i = 0; i < h; i++){
        printf("%d ", *(arr2 + i));
    }
}
void shellSort(int *arr2, int h){
    for(int interval = h / 2; interval > 0; interval /= 2 ){
        for(int i = interval; i < h; i++){
            int temp = *(arr2 + i);
            int j;
            for(j = i; j >= interval && arr2[j - interval] > temp; j -= interval){
                *(arr2 + j) = *(arr2 + j - interval);
            }
            *(arr2 + j) = temp;
        }
    }
}