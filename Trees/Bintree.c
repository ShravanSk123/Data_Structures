#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define count 5
struct Node
{
    int info;
    struct Node *llink,*rlink;
};
typedef struct Node *node;

node CreateTree(node r)
{
    node nn = (node*)malloc(sizeof(struct Node));
    printf("Enter the element\n");
    scanf("%d",&nn->info);
    nn->llink = nn->rlink = NULL;
    if(r==NULL) return nn;
    node pn = r; //pn -> parent node
    node pd = NULL; //pd -> previous node / predecessor
    char dir[20]; // indicates direction
    printf("Enter Valid Direction\n"); //example l,r,ll,lr,llr
    scanf("%s",dir);
    int i;
    for(i=0;i<strlen(dir);i++)
    {
        if(pn==NULL) break;
        pd = pn;
        if(dir[i]=='L' || dir[i]=='l')
            pn = pn->llink;
        else
            pn = pn->rlink;
    }
    //at the end of tree pn should be null.. if not then ERROR!!
    if(pn!=NULL || i!=strlen(dir))
    {
        printf("ERROR! Insertion is not possible\n");
        free(nn);
        return r;
    }
    if(dir[i-1]=='L'||dir[i-1]=='l') // since i is incremented in last iteration
        pd->llink = nn;
    else
        pd->rlink = nn;
        
    return r;
}
void printtree(node r,int space)
{
    if(r==NULL) return;
    space+=count;
    printtree(r->rlink,space);
    for(int i=count;i<space;i++)
        printf(" ");
    printf("%d\n",r->info);
    printtree(r->llink,space);
}
void print(node r)
{
    printtree(r,0);
}
void main()
{
	node r;
	r->info = 1;
	r->llink = r->rlink = NULL;
	int c;
	while(1)
	{
	    printf("1. Create Tree\n2. Print Tree\n");
	    scanf("%d",&c);
	    switch(c)
	    {
	        case 1: r = CreateTree(r);break;
	        case 2: print(r);break;
	        default: exit(0);
	    }
	}
}
