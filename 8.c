#include <stdio.h>

int w[10], x[10], d, count = 0, n;

void subset(int cs, int k, int r) {
    int i;
    x[k] = 1;
    if (cs + w[k] == d) {
        printf("\nSubset %d:\n", ++count);
        for (i=0; i<=k; i++)
            if (x[i]) printf("%d\t", w[i]);
    }
    else if (k + 1 < n && cs + w[k] + w[k+1] <= d) {
        subset(cs + w[k], k + 1, r - w[k]);
    }
    
    if (k + 1 < n && cs + r - w[k] >= d && cs + w[k] <= d) {
        x[k] = 0;
        subset(cs, k + 1, r - w[k]);
    }
}

int main() {
    int i, sum = 0;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    printf("\nEnter the elements in ascending order:\n");
    for (i=0; i<n; i++) {
        scanf("%d", &w[i]);
        sum += w[i];
    }
    printf("\nEnter the sum: ");
    scanf("%d", &d);
    
    if (sum < d) {
        printf("No solution\n");
        return 0;
    }
    
    subset(0, 0, sum);
    if (!count)
        printf("No solution\n");
        
    return 0;
}