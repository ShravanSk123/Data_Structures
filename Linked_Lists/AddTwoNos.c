//Adds two numbers written in reverse order linked lists
//Ex 7->5->NULL + 2->5->NULL is 57+52=109 => 9->0->1->NULL

#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode* node;

node InsertRear(node F, int x)
{
    node RN = (node)malloc(sizeof(struct ListNode));
    RN->val = x;
    if(F==NULL)
    {
        F = RN;
        return F;
    }
    node k = F;
    while(k->next!=NULL)
        k = k->next;
    k->next = RN;
    RN->next = NULL;
    return F;
}

node addTwoNumbers(node l1, node l2){
    node h1 = l1;
    node h2 = l2;
    //make two lists of equal size
    int c1=0,c2=0,c;
    while(h1!=NULL)
    {
        c1++;
        h1 = h1->next;
    }
    while(h2!=NULL)
    {
        c2++;
        h2 = h2->next;
    }
    
    if(c1>c2)
    {
        c = c1-c2;
        while(c--)
            l2 = InsertRear(l2,0);
    }
    else
    {
        c = c2-c1;
        while(c--)
            l1 = InsertRear(l1,0);
    }
    h1 = l1;
    h2 = l2;
    int flag = 0;
    node ans = NULL;
    //addition
    int k;
    while(h1->next!=NULL)
    {
        if(flag+h1->val+h2->val<10)
        {
            ans = InsertRear(ans,flag + h1->val + h2->val);
            flag = 0;
        }
        else if(flag+h1->val+h2->val>=10)
        {
            ans = InsertRear(ans, flag + h1->val + h2->val - 10);
            flag = 1;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    if(flag+h1->val+h2->val>=10)
    {
        ans = InsertRear(ans, flag + h1->val + h2->val - 10);
        ans = InsertRear(ans, 1);
    }
    else
    {
        ans = InsertRear(ans, flag + h1->val + h2->val);
    }
    return ans;
}
void main()
{
    node list1 = (node)malloc(sizeof(struct ListNode));
    node list2 = (node)malloc(sizeof(struct ListNode));
    InsertRear(list1,7);
    InsertRear(list1,9);
    InsertRear(list1,3);
    InsertRear(list1,2);
    printf("\n");
    InsertRear(list2,6);
    InsertRear(list2,5);
    list1 = list1->next;
    list2 = list2->next;
    node ans = NULL;
    ans = addTwoNumbers(list1,list2);
    while(ans!=NULL)
    {
        printf("%d ",ans->val);
        ans = ans->next;
    }
}
