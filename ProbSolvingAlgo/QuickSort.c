#include <stdio.h>
void swap(int *x,int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}
int Partition(int a[],int l,int h)
{
    int p = a[l];
    int i=l,j=h+1;
    do
    {
        do{
            i++;
        }while(a[i]<=p);
        do{
            j--;
        }while(a[j]>p);
        swap(&a[i],&a[j]);
    }while(i<j);
    swap(&a[i],&a[j]);
    swap(&a[l],&a[j]);
    return j;
}
void QuickSort(int a[],int l,int h)
{
    if(l<h)
    {
        int piv = Partition(a,l,h);
        QuickSort(a,l,piv-1);
        QuickSort(a,piv+1,h);
    }
}
int main() {
	int n;
	printf("Enter the size\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the array elements\n");
	for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
	QuickSort(a,0,n-1);
	for(int i=0;i<n;i++)
	    printf("%d ",a[i]);
	return 0;
}
