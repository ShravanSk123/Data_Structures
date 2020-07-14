#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int max(int x,int y)
{
    return (x>y)?x:y;
}
int main()
{
    int count[300];
    char s[100];
    printf("Enter the string\n");
    scanf("%s",s);
    int l = strlen(s);
    if(l==0) return 0;
    for(int i=0;i<300;i++)
        count[i]=0;
    int i=0,j=0;
    count[s[0]]++;
    int sub=1;
    while(j!=l-1)
    {
        if(count[s[j+1]]==0)
        {
            j++;
            count[s[j]]++;
            sub = max(sub,j-i+1);
        }
        else
            count[s[i++]]--;
    }
    printf("%d\n",sub);
    return 0;
}
