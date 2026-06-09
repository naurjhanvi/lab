#include <stdio.h>

int cost[10][10], parent[10], n;

int find(int x) {
    while (parent[x]) x = parent[x];
    return x;
}

int uni(int a, int b) {
    if (a != b) {
        parent[b] = a;
        return 1;
    }
    return 0;
}

int main() {
    int i, j, a, b, u, v, min, ne=1, mincost = 0;
    printf("\n\tImplementation of Kruskal's Algorithm\n");
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter the cost adjacency matrix:\n");
    for (i=1; i <= n; i++) {
        for (j=1; j<=n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) cost[i][j] = 999;
        }
    }
    
    printf("\nThe edges of Minimum Cost Spanning Tree are:\n");
    while (ne < n) {
        min=999;
        for (i=1; i <= n; i++) {
            for (j=1; j<=n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u,v)) {
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}