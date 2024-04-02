#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void memory(int ***arr, int **visitedNode, int n);
void inputGraph(int **arr, int e);
void bellmanKalaba(int **arr, int n, int startNode, int destNode);
void displayPath(int n, int *distance, int *predecessor, int destNode);
void freeMemory(int **arr, int *visitedNode, int n);
int main(){
    int n, e, startNode, destNode, **arr = NULL, *visitedNode = NULL;
    printf("Introduceti nr. de noduri:");
    scanf("%d", &n);
    printf("Introduceti nr. de muchii:");
    scanf("%d", &e);
    memory(&arr, &visitedNode, n);
    inputGraph(arr, e);
    printf("Introduceti nodul de start:");
    scanf("%d", &startNode);
    printf("Introduceti noul de destinatie:");
    scanf("%d", &destNode);
    bellmanKalaba(arr, n, startNode - 1, destNode - 1);
    freeMemory(arr, visitedNode, n);
    return 0;
}
void memory(int ***arr, int **visitedNode, int n){
    *arr = (int **)malloc(n * sizeof (int *));
    for(int i = 0; i < n; i++){
        (*arr)[i] = (int *) calloc(n , sizeof (int));
        if((*arr)[i] == NULL){
            printf("Eroare la alocare!");
            exit(1);
        }
    }
    *visitedNode = (int *) malloc(n * sizeof(int));
    if(*visitedNode == NULL){
        printf("Eroare la alocare!");
        exit(1);
    }
}
void inputGraph(int **arr, int e){
    printf("Introduceti muchiile (A, B, Greutatea):\n");
    for(int i = 0; i < e; i++){
        int A = 0, B = 0, weight = 0;
        scanf("%d %d %d", &A, &B, &weight);
        arr[B - 1][A - 1] = weight;
    }
}
void bellmanKalaba(int **arr, int n, int startNode, int destNode){
    int *distance = (int *)malloc(n * sizeof(int));
    int *predecessor = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        distance[i] = INT_MAX;
        predecessor[i] = -1;
    }
    distance[destNode] = 0;
    for(int k = 1; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] != 0 && distance[i] != INT_MAX && distance[i] + arr[i][j] < distance[j]){
                    distance[j] = distance[i] + arr[i][j];
                    predecessor[j] = i;
                }
            }
        }
    }
    displayPath(n, distance, predecessor, startNode);
    free(distance);
    free(predecessor);
}
void displayPath(int n, int *distance, int *predecessor, int destNode){
    printf("Costul minim este: %d\n", distance[destNode]);
    int currentNode = destNode;
    int path[n];
    int index = 0;
    while(currentNode != -1){
        path[index++] = currentNode;
        currentNode = predecessor[currentNode];
    }
    printf("Drumul minim este:");
    for(int i = 0; i < index; i++){
        printf("%d ", path[i] + 1);
    }
}
void freeMemory(int **arr, int *visitedNode, int n){
    for(int i = 0; i < n; i++){
        free(arr[i]);
    }
    free(arr);
    free(visitedNode);
}