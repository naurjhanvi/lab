#include <stdio.h>

void dij(int s, int cost[20][20], int d[20], int n) {
    int visited[20] = {0}, i, j, u, min, w;
    for (i = 1; i <= n; i++)
        d[i] = cost[s][i];
        
    visited[s] = 1;
    d[s] = 0;
    
    for (j=2; j <= n; j++) {
        min=999;
        for (i=1; i<=n; i++) {
            if (!visited[i] && d[i] < min) {
                min = d[u=i];
            }
        }
        visited[u] = 1;
        for (w=1; w<=n; w++) {
            if (!visited[w] && d[w] > d[u] + cost[u][w])
                d[w] = d[u] + cost[u][w];
        }
    }
}

int main() {
    int i, j, n, source;
    int cost[20][20], d[20];
    printf("Enter no. of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = 999;
        }
    }
    printf("\nEnter the source node: ");
    scanf("%d", &source);
    dij(source, cost, d, n);
    for (i=1; i <= n; i++)
        if (i != source)
            printf("\nShortest path from %d to %d is %d", source, i, d[i]);
            
    return 0;
}