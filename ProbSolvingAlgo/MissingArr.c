//missing number in array using XOR
//more efficient than summation method 
#include<stdio.h>
void main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    //XOR method
    int p=a[0]; //for xor in array
    int q=1; //for xor in 1..n number range
    for(int i=1;i<n;i++)
        p = p^a[i];
    for(int j=2;j<=n+1;j++)
        q = q^j;
    printf("%d\n",p^q);
}
