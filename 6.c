#include <stdio.h>
#define MAX 50

int p[MAX], w[MAX], n;

int knapsack(int i, int m) {
    if (i == n)
        return (w[n] <= m) ? p[n] : 0;
    if (w[i] > m)
        return knapsack(i + 1, m);
        
    int a = knapsack(i + 1, m);
    int b = knapsack(i + 1, m - w[i]) + p[i];
    return (a > b) ? a : b;
}

int main() {
    int m, i;
    printf("Enter no. of objects: ");
    scanf("%d", &n);
    printf("\nEnter the weights:\n");
    for (i=1; i<=n; i++)
        scanf("%d", &w[i]);
        
    printf("\nEnter the profits:\n");
    for (i=1; i<=n; i++)
        scanf("%d", &p[i]);
        
    printf("\nEnter the knapsack capacity: ");
    scanf("%d", &m);
    printf("\nThe optimal solution is: %d\n", knapsack(1, m));
    
    return 0;
}