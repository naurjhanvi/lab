#include <stdio.h>

int cost[10][10], n, mincost = 0;

int prims() {
    int near[10], i, j, k, u, min;
    for (i=2; i <= n; i++) near[i] = 1;
    near[1] = 0;
    
    for (i=1; i<n; i++) {
        min=999;
        for (j=1; j <= n; j++) {
            if (near[j] && cost[j][near[j]] < min) {
                min = cost[j][near[j]];
                u=j;
            }
        }
        mincost += min;
        printf("The Minimum edge is %d -> %d \t cost = %d\n", near[u], u, min);
        near[u] = 0;
        for (k=1; k <= n; k++) {
            if (near[k] && cost[k][near[k]] > cost[k][u])
                near[k] = u;
        }
    }
    return mincost;
}

int main() {
    int i, j;
    printf("********* PRIMS ALGORITHM *********\n");
    printf("Enter the number of nodes:\n");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (i=1; i <= n; i++)
        for (j=1; j <= n; j++)
            scanf("%d", &cost[i][j]);
            
    printf("Minimum Spanning Tree Edges and costs are:\n");
    mincost = prims();
    printf("The minimum spanning tree cost is %d\n", mincost);
    return 0;
}