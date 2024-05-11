#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#define V 8

bool visited[V];
int graph[V][V];

int min(int a, int b) {
    return a < b ? a : b;
}

bool dfs(int s, int t, int parent[]) {
    visited[s] = true;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && graph[s][v] > 0) {
            parent[v] = s;
            if (v == t) {
                return true;
            }  
            if (dfs(v, t, parent)) {
                return true;
            }
        }
    }
    return false;
}

int bfs(int s, int t, int parent[]) {
    memset(visited, 0, sizeof(visited));
    visited[s] = true;
    parent[s] = -1;

    int queue[V];
    int front = 0, rear = 0;
    queue[rear++] = s;

    while (front != rear) {
        int u = queue[front++];
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = true;
                if (v == t) {
                    return true;
                }
            }
        }
    }
    return false;
}

int fordFulkerson(int source, int dest) {
    int parent[V];
    int maxFlow = 0;
    while (dfs(source, dest, parent)) {
        memset(visited, 0, sizeof(visited));    
        int pathFlow = INT_MAX;
        for (int v = dest; v != source; v = parent[v]) {
            int u = parent[v];
            printf("%d->", u);
            pathFlow = min(pathFlow, graph[u][v]);
        }
        printf("Minim: %d ", pathFlow);
        printf("\n");
        for (int v = dest; v != source; v = parent[v]) {
            int u = parent[v];
            graph[u][v] -= pathFlow;
            graph[v][u] += pathFlow;
            printf("graph[%d][%d] -= %d -> %d\n", u, v, pathFlow, graph[u][v]);
            printf("graph[%d][%d] += %d -> %d\n", v, u, pathFlow, graph[v][u]);
           
        }
        maxFlow += pathFlow;
    }
    while (bfs(source, dest, parent)) {
        int pathFlow = INT_MAX;
        for (int v = dest; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, graph[u][v]);
        }
        for (int v = dest; v != source; v = parent[v]) {
            int u = parent[v];
            graph[u][v] -= pathFlow;
            graph[v][u] += pathFlow;
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}

int main() {
    memset(graph, 0, sizeof(graph));
    graph[0][1] = 17;
    graph[0][5] = 12;
    graph[1][2] = 5;
    graph[1][3] = 8;
    graph[2][3] = 3;
    graph[3][7] = 10;
    graph[6][3] = 4;
    graph[6][7] = 10;
    graph[5][4] = 4;
    graph[4][6] = 3;
    graph[5][6] = 6;
    int source = 0;
    int dest = 7;
    printf("Fluxul maxim este: %d\n", fordFulkerson(source, dest));
    return 0;
}
