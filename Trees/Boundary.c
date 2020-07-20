#include<stdio.h>
#include<stdlib.h>
struct node { 
    int data; 
    struct node *left, *right; 
};
struct node* newNode(int data) 
{ 
    struct node* temp = (struct node*)malloc(sizeof(struct node)); 
  
    temp->data = data; 
    temp->left = temp->right = NULL; 
  
    return temp; 
} 

void Left(struct node *p)
{
    //prints the left boundary excluding leaf nodes
    if(p==NULL) return;
    if(p->left!=NULL)
    {
        printf("%d ",p->data);
        Left(p->left);
    }
    else if(p->right!=NULL)
    {
        printf("%d ",p->data);
        Left(p->right);
    }
}

void Leaf(struct node *p)
{
    //prints all leaf nodes
    if(p==NULL) return;
    if(p->left==NULL && p->right==NULL)
        printf("%d ",p->data);
    if(p->left!=NULL)
        Leaf(p->left);
    if(p->right!=NULL)
        Leaf(p->right);
}

void Right(struct node *p)
{
    //prints the right boundary excluding leaf nodes
    if(p==NULL) return;
    if(p->right!=NULL)
    {
        Right(p->right);
        printf("%d ",p->data);
    }
    else if(p->left!=NULL)
    {
        Right(p->left);
        printf("%d ",p->data);
    }
}
void Boundary(struct node *p)
{
    if(p==NULL) return;
    printf("%d ",p->data);
    Left(p->left);
    Leaf(p);
    Right(p->right);
}

void main() 
{ 
    // Creating a binary tree
    struct node* r = newNode(20); 
    r->left = newNode(7); 
    r->left->left = newNode(44); 
    r->left->right = newNode(125); 
    r->left->right->left = newNode(120); 
    r->left->right->right = newNode(6); 
    r->right = newNode(23); 
    r->right->right = newNode(15);
    r->right->right->right = newNode(105);
  
    Boundary(r);
} 
