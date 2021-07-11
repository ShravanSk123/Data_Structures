//Using Dynamic Programming approach

#include <stdio.h>
#include<stdlib.h>

int max(int i, int j)
{
    return (i>j)?i:j;
}

int knapsack(int k, int n, int* arr) {
    int mat[n+1][k+1];
    for (int i=0;i<=n;i++) 
        mat[i][0]=0;
    for (int i=0;i<=k;i++) 
        mat[0][i]=0; // case 1 if no object remains OR capacity reaches 0 i.e., first row and first columns of matrix
  
    for (int i=1;i<=n;i++) 
    {
        for (int j=1;j<=k;j++)
        {
            if (arr[i - 1] <= j)
                mat[i][j] = max(arr[i-1] + mat[i][j - arr[i - 1]], mat[i - 1][j]); // case 2 main formula
            else mat[i][j] = mat[i - 1][j]; // case 3 when weight exceeds the given total capacity
        }
    }
  
    return mat[n][k]; // returns the sum of objects <= target capacity
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--) {
        int n, k;
        scanf("%d",&n);
        scanf("%d",&k);
        int *arr;
        arr = (int*)malloc(n*sizeof(int));
        for (int i = 0; i < n; i++) 
            scanf("%d",&arr[i]);
        printf("%d\n", knapsack(k, n, arr));
    }
    return 0;
}
