// Performing operations on linked lists
// Program to insert and delete singly linked lists
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;
NODE InsertFront(NODE);
NODE InsertByPosition(NODE);
NODE InsertRear(NODE);
NODE DeleteFront(NODE);
NODE DeleteByPosition(NODE);
NODE CreateNode();
NODE Search(NODE);
NODE Reverse(NODE);
int NodeLength(NODE);
void Display(NODE);
void main()
{
    NODE First = NULL;
    int ch,count;
    for(;;)
    {
        printf("\n1 Insert at beginning\n2 Insert at the end\n3 Delete the first\n4 Delete by position\n5 Insert at any Position\n6 Search an element\n");
        printf("7 Reverse the list\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: First = InsertFront(First);
                    Display(First);
                    break;
            case 2: First = InsertRear(First);
                    Display(First);
                    break;
            case 3: First = DeleteFront(First);
                    Display(First);
                    break;
            case 4: First = DeleteByPosition(First);
                    Display(First);
                    break;
            case 5: First = InsertByPosition(First);
                    Display(First);
                    break;
            case 6: First = Search(First);
                    break;
            case 7: First = Reverse(First);
                    Display(First);
                    break;
            default: exit(0);
        }
    }
}
NODE CreateNode()
{
    NODE F;
    F = (NODE)malloc(sizeof(NODE));
    return F;
}
NODE InsertFront(NODE F)
{
    NODE NN;
    NN = CreateNode();
    printf("Enter the first element\n");
    scanf("%d",&NN->info);
    NN->link = F;
    if(F==NULL)
    {
        F = NN;
        return F;
    }
    else
    {
        NN->link = F;
        F = NN;
        return F;
    }
}
NODE InsertRear(NODE F)
{
    NODE RN;
    RN = CreateNode();
    printf("Enter the last element\n");
    scanf("%d",&RN->info);
    if(F==NULL)
    {
        F = RN;

        return F;
    }
    else
    {
        NODE LN;
        LN = F;
        while(LN->link!=NULL)
        {
            LN = LN->link;
        }
        LN->link = RN;
        RN->link = NULL;

        return F;
    }
}
void Display(NODE F)
{
    while(F!=NULL)
    {
        printf("%d\t",F->info);
        F = F->link;
    }
}
int NodeLength(NODE F)
{
    int count = 1;
    NODE K;
    K = F;
    while(K!=NULL)
    {
        count++;
        K = K->link;
    }

    return count;
}
NODE DeleteFront(NODE F)
{
    if(F==NULL)
    {
        printf("The list is already empty\n");
        return;
    }
    else
    {
        NODE P;
        P = F;
        printf("Element %d is deleted\n",P->info);
        F = P->link;
        P->link = NULL;
        free(P);
        return F;
    }
}
NODE DeleteByPosition(NODE F)
{
    int pos,i=1;
    printf("Enter the position to be deleted\n");
    scanf("%d",&pos);
        NODE P,Q;
        P = F;
        while(i<pos-1)
        {
            P = P->link;
            i++;
        }
        Q = P->link;
        P->link = Q->link;
        Q->link = NULL;
        free(Q);
        return F;
}
NODE InsertByPosition(NODE F)
{
    int pos;
    int i=1;
    NODE NN,P;
    NN = CreateNode();
    NN->link = NULL;
    printf("Enter the position\n");
    scanf("%d",&pos);
    printf("Enter the element you want to insert\n");
    scanf("%d",&NN->info);
    P = F;
    while(i<pos-1)
    {
        P = P->link;
        i++;
    }
    NN->link = P->link;
    P->link = NN;
    return F;
}
NODE Search(NODE F)
{
    int s,i=1;
    NODE P;
    P = F;
    printf("Enter the element you want to search\n");
    scanf("%d",&s);

    while(P!=NULL)
    {
        if(P->info == s)
        {
            printf("Element found at position %d",i);
            return;
        }
        P = P->link;
        i++;
    }
}
NODE Reverse(NODE F)
{
    NODE T;
    NODE LN = NULL;
    while(F!=NULL)
    {
        T = F;
        F = F->link;
        T->link = LN;
        LN = T;
    }
    return T;
}
