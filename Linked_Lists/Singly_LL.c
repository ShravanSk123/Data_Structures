// Program to insert and delete SINGLY linked lists
// All operations on singly linked lists
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
NODE DeleteRear(NODE);
NODE DeleteByPosition(NODE);
NODE CreateNode();
NODE Search(NODE);
NODE Reverse(NODE);
NODE InsertBefore(NODE);
NODE InsertAfter(NODE);
int NodeLength(NODE);
void Display(NODE);
void main()
{
    NODE First = NULL;
    int ch;
    for(;;)
    {
        printf("\n***************************************** \n");
        printf("\n1 Insert at beginning\n2 Insert at the end\n3 Delete the first\n4 Delete the last\n5 Delete by position\n6 Insert at any Position\n7 Search an element\n");
        printf("8 Reverse the list\n9 Insert before a specific node\n10 Insert after a specific node\n");
        printf("\n***************************************** \n");
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
            case 4: First = DeleteRear(First);
                    Display(First);
                    break;
            case 5: First = DeleteByPosition(First);
                    Display(First);
                    break;
            case 6: First = InsertByPosition(First);
                    Display(First);
                    break;
            case 7: First = Search(First);
                    break;
            case 8: First = Reverse(First);
                    Display(First);
                    break;
            case 9: First = InsertBefore(First);
                    Display(First);
                    break;
            case 10: First = InsertAfter(First);
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
NODE DeleteRear(NODE F)
{
    NODE P,Q;
    P = F;
    if(F==NULL)
    {
        printf("The list is already empty\n");
        return;
    }
    if(F->link = NULL)
    {
        printf("Deleted Element: %d",F->info);
        free(F);
        return NULL;
    }
    
    while(P->link->link!=NULL)
    {
        P = P->link;
    }
    free(P->link);
    P->link = NULL;
    return F;
}
NODE DeleteByPosition(NODE F)
{
    if(F==NULL)
    {
        printf("List is already empty\n");
        return NULL;
    }
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
        printf("Element deleted: %d\n",Q->info);
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
    if(F==NULL && pos>1)
    {
        printf("Invalid position. Please reenter\n");
        printf("Enter the position\n");
        scanf("%d",&pos);
    }
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
    if(F==NULL)
    {
        printf("Nothing to search! List is EMPTY..");
        return;
    }
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
    if(F==NULL || F->link ==NULL)
    {
        printf("Add atleast 2 elements to perform this function\n");
        return;
    }
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
NODE InsertBefore(NODE F)
{
    if(F==NULL)
    {
        printf("The list is empty. Add at least 2 elements to perform this operation\n");
        return;
    }
    NODE P,NN;
    NN = CreateNode();
    P = F;
    int x;
    printf("Before which element\n");
    scanf("%d",&x);
    printf("Enter the element\n");
    scanf("%d",&NN->info);
    while(P->link->info!=x)
    {
        P = P->link;
    }
    NN->link = P->link;
    P->link = NN;
    return F;
}
NODE InsertAfter(NODE F)
{
    if(F==NULL)
    {
        printf("The list is empty. Add at least 1 element to perform this operation\n");
        return;
    }
    NODE P,NN;
    NN = CreateNode();
    P = F;
    int x;
    printf("After which element\n");
    scanf("%d",&x);
    printf("Enter the element\n");
    scanf("%d",&NN->info);
    while(P->info!=x)
    {
        P = P->link;
    }
    NN->link = P->link;
    P->link = NN;
    return F;
}
