//max sum in subarray
//Kadane's algorithm
#include<stdio.h>
void main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int max_sofar=a[0]; //this holds final answer
    int new_max=0;
    int start=0,end=0,s=0;
    for(int i=0;i<n;i++)
    {
        new_max += a[i];
        if(max_sofar<new_max)
        {
            max_sofar = new_max;
            start = s;
            end = i;
        }
        if(new_max<0)
        {
            new_max=0;
            s = i+1; // subarray starting index changes
        }
    }
    printf("The maximum subarray sum is %d\n",max_sofar);
    printf("The subarray is\n");
    for(int i=start;i<=end;i++)
        printf("%d ",a[i]);
    printf("\n");
}
