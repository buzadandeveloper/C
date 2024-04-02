    #include <stdio.h>
    #include <stdlib.h>
    #include <limits.h>
    void memory(int ***arr, int **visitedNode, int n);
    void inputGraph(int **arr, int e);
    void bfs(int **arr, int *visitedNode, int n, int startNode, int destNode, int distance[n], int previousNode[n]);
    void ford(int **arr, int *visitedNode, int n, int startNode, int destNode);
    void freeMemory(int **arr, int *visitedNode, int n);
    int main(){
        int n, e, startNode, destNode, **arr = NULL, *visitedNode = NULL;
        printf("Introduceti nr. de noduri:");
        scanf("%d", &n);
        printf("Introduceti nr. de muchii:");
        scanf("%d", &e);
        memory(&arr, &visitedNode, n);
        inputGraph(arr, e);
        printf("Introduceti nodul de inceput:");
        scanf("%d", &startNode);
        printf("Introduceti nodul de sfarsit:");
        scanf("%d", &destNode);
        ford(arr, visitedNode, n, startNode, destNode);
        freeMemory(arr, visitedNode, n);
        return 0;
    }
    void memory(int ***arr, int **visitedNode, int n){
        *arr = (int **) malloc(n * sizeof (int *));
        for(int i = 0; i < n; i++){
            (*arr)[i] = (int *) calloc(n, sizeof(int));
            if((*arr)[i] == NULL){
                printf("Eroare la alocare!");
                exit(1);
            }
        }
        *visitedNode = (int *) calloc(n * n, sizeof (int));
        if(visitedNode == NULL){
            printf("Eroare la alocare!");
            exit(1);
        }
    }
    void inputGraph(int **arr, int e){
        printf("Introduceti muchiile (A, B, Greutatea):\n");
        for(int i = 0 ; i < e; i++){
            int A = 0, B = 0 , weight = 0;
            scanf("%d %d %d", &A, &B, &weight);
            arr[A - 1][B - 1] = weight;
        }
    }
    void bfs(int **arr, int *visitedNode, int n, int startNode, int destNode, int distance[n], int previousNode[n]){
        int queue[n];
        int front = -1, rear = -1;
        queue[rear++] = startNode;

        while(front != rear){
            int currentNode = queue[front++];
            visitedNode[currentNode - 1] = 1;
            for(int i = 0; i < n; i++){
                if(arr[currentNode - 1][i] != 0 && !visitedNode[i] && distance[currentNode - 1]
                + arr[currentNode - 1][i] < distance[i]){
                    distance[i] = distance[currentNode - 1] +  arr[currentNode - 1][i];
                    previousNode[i] = currentNode - 1;
                    queue[rear++] = i + 1;
                }
            }
            if(front == rear){
                front = -1;
                rear = -1;
            }
        }
    }
    void ford(int **arr, int *visitedNode, int n, int startNode, int destNode){
        int distance[n], previousNode[n];
        for(int i = 0; i < n; i++){
            distance[i] = INT_MAX;
            previousNode[i] = -1;
        }
        distance[startNode - 1] = 0;
        bfs(arr, visitedNode, n, startNode, destNode, distance, previousNode);
        if(distance[destNode - 1] == INT_MAX){
            printf("Nu exista drum de la nodul %d la nodul %d", startNode, destNode);
            return;
        }
        int currentNode = destNode;
        int path[n];
        int numberPathNodes = 0;

        while(currentNode != -1 && currentNode != startNode){
            path[numberPathNodes++] = currentNode;
            currentNode = previousNode[currentNode - 1] + 1;
        }
        path[numberPathNodes++] = startNode;
        for(int i = numberPathNodes - 1; i >= 0; i--){
            printf("%d ", path[i]);
        }
        printf("\n");
        printf("Costul minim de la nodul %d la nodul %d este %d", startNode, destNode, distance[destNode - 1]);
    }
    void freeMemory(int **arr, int *visitedNode, int n){
        for(int i = 0; i < n; i++){
            free(arr[i]);
        }
        free(arr);
        free(visitedNode);
    }
