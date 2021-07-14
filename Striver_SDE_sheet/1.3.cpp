// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


// } Driver Code Ends
//User function Template for C

int nextGap(int gap) {
    if (gap <= 1)  return 0;
    return (gap / 2) + (gap % 2);  //alternative to ceil function
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;

}
//Function to merge the arrays.
void merge(int* arr1, int* arr2, int n, int m)
{
    int i, j, gap = n + m;
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {

        // comparing elements in the first array.
        for (i = 0; i + gap < n; i++)
            if (arr1[i] > arr1[i + gap])
                swap(&arr1[i], &arr1[i + gap]);

        // comparing elements in both arrays.
        for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)
            if (arr1[i] > arr2[j])
                swap(&arr1[i], &arr2[j]);

        if (j < m) {
            // comparing elements in the second array.
            for (j = 0; j + gap < m; j++)
                if (arr2[j] > arr2[j + gap])
                    swap(&arr2[j], &arr2[j + gap]);
        }
    }
}

// { Driver Code Starts.

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d", &n);
        scanf("%d", &m);
        int *arr1;
        arr1 = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            scanf("%d", &arr1[i]);
        int *arr2;
        arr2 = (int*)malloc(m * sizeof(int));
        for (int i = 0; i < m; i++)
            scanf("%d", &arr2[i]);

        merge(arr1, arr2, n, m);
        for (int i = 0; i < n; i++)
            printf("%d ", arr1[i]);
        for (int i = 0; i < m; i++)
            printf("%d ", arr2[i]);
        printf("\n");
    }
    return 0;
}  // } Driver Code Ends