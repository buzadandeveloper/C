#include <stdio.h>
#include <stdlib.h>
void memory(int n, int ***arr, int **visitedNode);
void freeMemory(int n, int **arr, int *visitedNode);
void output(int n, int **arr);
void paths(int e, int **arr);
void depthFirstSearch(int nodeStart, int n, int **arr, int *visitedNode);
int main() {
    int **arr = NULL, *visitedNode = NULL, n, e, startNode;
    printf("Introduceti nr. de varfuri:");
    scanf("%d", &n);
    printf("Introduceti nr. de muchii:");
    scanf("%d", &e);
    printf("Introduceti varful de start:");
    scanf("%d", &startNode);
    memory(n, &arr, &visitedNode);
    paths(e, arr);
    output(n, arr);
    printf("\n");
    printf("Inceput din varful %d: ",startNode);
    depthFirstSearch(startNode, n, arr, visitedNode);
    freeMemory(n, arr, visitedNode);
    return 0;
}
void memory(int n, int ***arr, int **visitedNode) {
    *arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        (*arr)[i] = (int *)calloc(n, sizeof(int));
    }
    *visitedNode = (int *) calloc(n * n,  sizeof (int));
    if(*visitedNode == NULL) {
        printf("Eroare la alocare!");
    }
}
void freeMemory(int n, int **arr, int *visitedNode) {
    if (arr != NULL) {
        for (int i = 0; i < n; i++) {
            free(arr[i]);
        }
        free(arr);
    }
    free(visitedNode);
}
void output(int n, int **arr) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
void paths(int e, int **arr) {
    printf("Introduceti drumurile A si B:\n");
    for (int i = 0; i < e; i++) {
        int A = 0, B = 0;
        scanf("%d%d", &A, &B);
        arr[A][B] = 1;
        arr[B][A] = 1;
    }
}
void depthFirstSearch(int nodeStart, int n, int **arr, int *visitedNode){
    visitedNode[nodeStart] = 1;
    printf("%d ", nodeStart);
    for(int i = 0; i < n; i++){
        if(arr[nodeStart][i] && !visitedNode[i]){
            depthFirstSearch(i, n, arr, visitedNode);
        }
    }
}
