#include <stdio.h>

int a[10][10], indegree[20], n;

void topological() {
    int stack[20], top=-1;
    int t[20], k=0, i, j, u;
    
    for (j=1; j<=n; j++)
        for (i=1; i <= n; i++)
            indegree[j] += a[i][j];
            
    for (i = 1; i <= n; i++)
        if (indegree[i] == 0)
            stack[++top] = i;
            
    while (top != -1) {
        u = stack[top--];
        t[k++] = u;
        for (i=1; i<=n; i++)
            if (a[u][i] && --indegree[i] == 0)
                stack[++top] = i;
    }
    printf("\nTopological Ordering is :\n");
    for (i=0; i<k; i++)
        printf("%d ", t[i]);
}

int main() {
    int i, j;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i=1; i <= n; i++)
        for (j=1; j <= n; j++)
            scanf("%d", &a[i][j]);
            
    topological();
    return 0;
}