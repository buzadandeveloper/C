#include <stdio.h>
#include <stdlib.h>
void memory(int ***arr, int **visitedNode, int n);
void freeMemory(int **arr, int *visitedNode, int n);
void paths(int **arr, int e);
void output(int **arr, int n);
void breadthFirstSearch(int startNode, int n, int **arr, int *visitedNode);
int main(){
    int **arr = NULL, *visitedNode = NULL, n, e, startNode;
    printf("Introduceti nr. de varfuri:");
    scanf("%d", &n);
    printf("Introduceti nr. de muchii:");
    scanf("%d", &e);
    printf("Introduceti varful de start:");
    scanf("%d", &startNode);
    memory(&arr, &visitedNode, n);
    paths(arr, e);
    output(arr, n);
    printf("\n");
    breadthFirstSearch(startNode, n, arr, visitedNode);
    freeMemory(arr, visitedNode, n);
    return 0;
}
void memory(int ***arr, int **visitedNode, int n){
    *arr = (int **) malloc(n * sizeof (int*));
    for(int i = 0; i < n; i++){
        (*arr)[i] = (int *) calloc(n , sizeof (int));
        if((*arr)[i] == NULL){
            printf("Eroare la alocare!");
        }
    }
    *visitedNode = (int *) calloc(n * n, sizeof (int));
    if(visitedNode == NULL){
        printf("Eroare la alocare!");
    }
}
void freeMemory(int **arr, int *visitedNode, int n){
    for(int i = 0; i < n; i++){
        free(arr[i]);
    }
    free(arr);
    free(visitedNode);
}
void paths(int **arr, int e){
    printf("Introduceti drumurile A si B:\n");
    for(int i = 0; i < e; i++){
        int A = 0, B = 0;
        scanf("%d%d", &A, &B);
        arr[A][B] = 1;
        arr[B][A] = 1;
    }
}
void output(int **arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
void breadthFirstSearch(int startNode, int n, int **arr, int *visitedNode){
    int queue[n];
    int front = -1, rear = -1;
    visitedNode[startNode] = 1;
    queue[rear++] = startNode;
    while(front != rear){
        int currentNode = queue[front++];
        printf("%d ", currentNode);
        for(int i = 0; i < n; i++){
            if(arr[currentNode][i] && !visitedNode[i]){
                visitedNode[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}
