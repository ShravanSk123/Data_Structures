//majority element in given array-- *occurs more than n/2 times*
//O(n) complexity using moore voting algo
#include<stdio.h>
void main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int cand=a[0]; //suspect! this might be majority
    int cnt=1; //useful just for finding the suspect
    for(int i=1;i<n;i++)
    {
        if(cand==a[i])
            cnt++;
        else cnt--;
        if(cnt==0)
        {
            cand = a[i];
            cnt=1;
        }
    }
    //now check if the suspect(cand) is repeated more than n/2 times
    int s = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==cand)
            s++;
    }
    if(s>n/2)
        printf("Majority element is %d\n",cand);
    else
        printf("No majority element exists\n");
}
