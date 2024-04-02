#include <stdio.h>
#include <stdlib.h>
void menu(int ***arr, int ***graph, int n, int m);
void memory(int ***arr, int ***graph, int n, int m);
void input(int **arr, int n, int m);
void output(int **arr, int n, int m);
void directedGraph(int **arr, int m);
void undirectedGraph(int **arr, int m);
void incidentGraphOriented(int **arr, int m);
void findRoads(int **arr, int **graph, int n, int m);
void freeMemory(int **arr, int **graph, int n);
int main(){
    int **arr = NULL, **graph = NULL, n ,m;
    printf("Introduceti nr. de varfuri:");
    scanf("%d", &n);
    printf("Introduceti nr. de muchii:");
    scanf("%d", &m);
    menu(&arr, &graph, n, m);
    return 0;
}
void menu(int ***arr, int ***graph, int n, int m){
    int option;
    printf("Alegeti optiunile:\n"
           "0. Iesire\n"
           "1. Alocarea memoriei.\n"
           "2. Introducerea drumului a grafului orientat.\n"
           "3. Introducerea drumului a grafului neorientat.\n"
           "4. Introducerea drumului a grafului incident orientat.\n"
           "5. Introduceti matricea drumului\n"
           "6. Output\n"
           "7. Output matricea drumului\n"
           "8. Eliberarea memoriei\n"
    );
    scanf("%d", &option);
    switch (option) {
        case 0:{
            printf("Sa efectuat iesirea");
            freeMemory(*arr, *graph, n);
            exit(0);
        }
        case 1:{
            memory(arr, graph, n, m);
            menu(arr, graph, n, m);
            break;
        }
        case 2:{
            directedGraph(*arr, m);
            menu(arr, graph, n, m);
            break;
        }
        case 3:{
            undirectedGraph(*arr, m);
            menu(arr, graph, n, m);
            break;
        }
        case 4:{
            incidentGraphOriented(*arr, m);
            menu(arr, graph, n, m);
            break;
        }
        case 5:{
            findRoads(*arr, *graph, n, m);
            menu(arr, graph, n, m);
            break;
        }
        case 6:{
            output(*arr, n, m);
            menu(arr, graph, n, m);
            break;
        }
        case 7:{
            output(*graph, n, m);
            break;
        }
        case 8:{
            freeMemory(*arr, *graph, n);
            menu(arr, graph, n, m);
            break;
        }
    }
}
void memory(int ***arr, int ***graph, int n, int m){
    *arr = (int **) malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++){
        (*arr)[i] = (int *)calloc(m,  sizeof(int));
        if((*arr)[i] == NULL){
            printf("Eroare la alocare");
        }
    }
    *graph = (int **) malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++){
        (*graph)[i] = (int *)calloc(m,  sizeof(int));
        if((*graph)[i] == NULL){
            printf("Eroare la alocare");
        }
    }
}
void input(int **arr, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &arr[i][j]);
        }
    }
}
void output(int **arr, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
void directedGraph(int **arr, int m){
    for(int i = 0; i < m; i++){
        int A = 0, B = 0;
        printf("\nIntroduceti drumul A B:");
        scanf("%d%d", &A, &B);
        arr[A - 1][B - 1] = 1;
    }
}
void undirectedGraph(int **arr, int m){
    for(int i = 0; i < m; i++){
        int A = 0, B = 0;
        printf("\nIntroduceti drumul A B:");
        scanf("%d%d", &A, &B);
        arr[A - 1][B - 1] = 1;
        arr[B - 1][A - 1] = 1;
    }
}
void incidentGraphOriented(int **arr, int m){
    for(int i = 0; i < m; i++){
        printf("\nIntroduceti drumul A B:");
        int A = 0, B = 0;
        scanf("%d%d", &A, &B);
        arr[A - 1][i] = 1;
        arr[B - 1][i] = -1;
    }
}
void findRoads(int **arr,  int**graph,  int n, int m){
    printf("Introduceti:\n");
    input(arr, n, m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            graph[i][j] = arr[i][j];
        }
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(graph[i][k] && graph[k][j])
                    graph[i][j] = 1;
            }
        }
    }
}
void freeMemory(int **arr, int **graph, int n){
    if(arr != NULL ){
        for(int i = 0; i < n; i++){
            free(arr[i]);
        }
        free(arr);
    }
    if(graph != NULL){
        for(int i = 0; i < n; i++){
            free(graph[i]);
        }
        free(graph);
    }
}