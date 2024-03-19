#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
void memory(int ***arr, int **arr2, int n);
void freeMemory(int **arr, int *arr2, int n);
void input(int **arr, int n);
void fillRandom(int **arr, int n);
void output(int **arr, int n);
void output1D(int *arr2, int h);
void takeColumn(int **arr, int *arr2, int n, int *h, int k);
void countingSort(int *arr2, int h);
int getMax(int *arr2, int h);
int main() {
    int **arr = NULL, *arr2 = NULL, n, h, k;
    printf("Introduceti dimensiunea array-ului 2D:\n");
    scanf("%d", &n);
    printf("Introduceti nr. coloanei:\n");
    scanf("%d", &k);
    memory(&arr, &arr2, n);
    fillRandom(arr, n);
    output(arr, n);
    takeColumn(arr, arr2, n, &h, k);
    output1D(arr2, h);\
    countingSort(arr2, h);
    printf("\n");
    output1D(arr2, h);
    freeMemory(arr, arr2, n);
    return 0;
}
void memory(int ***arr, int **arr2, int n){
    *arr = (int **) malloc(n * sizeof (int *));
    for(int i = 0; i < n; i++){
        (*arr)[i] = (int *) calloc(n, sizeof (int));
        if((*arr)[i] == NULL){
            printf("Eroare la alocare\n");
            exit(1);
        }
    }
    *arr2 = (int *) calloc(n * n, sizeof (int));
    if(*arr2 == NULL){
        printf("Eroare la alocare");
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
void input(int **arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", (*(arr + i) + j));
        }
    }
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
void takeColumn(int **arr, int *arr2, int n, int *h, int k){
    printf("\n");
    *h = 0;
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            if(j == k){
                arr2[(*h)++] = *(*(arr + i) + j);
            }
        }
    }
}
int getMax(int *arr2, int h){
    int max = INT_MIN;
    for(int i = 0; i < h; i++){
        if(arr2[i] > max){
            max = arr2[i];
        }
    }
    return max;
}
void countingSort(int *arr2, int h){
    int max = getMax(arr2, h);
    int *count = (int *) calloc(max + 1, sizeof (int));
    for(int i = 0; i < h; i++){
        count[arr2[i]]++;
    }
    int k = 0;
    for(int i = 0; i <= max; i++ ){
        while(count[i] >  0){
            arr2[k++] = i;
            count[i]--;
        }
    }
    free(count);
}


