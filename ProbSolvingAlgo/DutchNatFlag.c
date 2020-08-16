//dutch national flag problem
//segregate all 0 1 2s in the given array 
#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    //segregate method in O(n)
    int low=0,mid=0,high=n-1;
    while(mid<=high)
    {
        switch(a[mid])
        {
            case 0:
                swap(&a[low],&a[mid]);
                low++;mid++;break;
            case 1:
                mid++;break;
            case 2:
                swap(&a[high],&a[mid]);
                high--;break;
            default:
                exit(0);
        }
    }
    printf("Segregated array is:-\n");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
