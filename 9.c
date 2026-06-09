#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int a[], int n) {
    int i, j, min, t;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        t = a[i];
        a[i] = a[min];
        a[min] = t;
    }
}

int main() {
    int n, i;
    
    printf("N\t\tTime Taken (Seconds)\n");
    printf("------------------------------------\n");
    
    srand(time(NULL));

    for (n = 5000; n <= 50000; n += 5000) {
        // Correctly casted for C++ compatibility 
        int *a = (int *)malloc(n * sizeof(int)); 
        
        for (i = 0; i < n; i++) {
            a[i] = rand() % 10000; 
        }
        
        clock_t start = clock();
        selectionSort(a, n);
        clock_t end = clock();
        
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%d\t\t%lf\n", n, time_taken);
        
        free(a);
    }
    
    return 0;
}