#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

int IsOperand(char c)
{
    switch(c)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '$':
        case '^':
        case '(':
        case ')': return 0;
        default: return 1;
    }
}

struct Stack{
    char items[SIZE];
    int top;
};
typedef struct Stack stk;

void push(stk *s,char item)
{
    if(s->top==SIZE-1)
    {
        printf("Stack is full\n");
        return;
    }
    s->top++;
    s->items[s->top] = item;
}

char pop(stk *s)
{
    if(s->top==-1)
    {
        printf("Stack is empty\n");
        return;
    }
    return s->items[s->top--];
}

int stkprec(char opr)
{
    switch(opr)
    {
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '$':
        case '^': return 6;
        case '(': return 0;
    }
}

int inprec(char opr)
{
    switch(opr)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 3;
        case '$':
        case '^': return 7;
        case '(': return 9;
        case ')': return 0;
    }
}

void infix_pre(char in[],char pre[])
{
    int i=0,j=0;
    char symb,k;
    stk oprstk;
    oprstk.top = -1;
    while((symb=in[i++])!='\0')
    {
        if(IsOperand(symb))
        {
            pre[j++] = symb;
        }
        else
        {
            while(oprstk.top!=-1 && stkprec(oprstk.items[oprstk.top])>=inprec(symb))
            {
                if(symb==')')
                {
                    while(oprstk.items[oprstk.top]!='(')
                    {
                        pre[j++] = pop(&oprstk);
                    }
                        k  = pop(&oprstk);
                        break;
                }
                else pre[j++] = pop(&oprstk);
            }
            if(symb!=')')
            {
                push(&oprstk,symb);
            }
        }
    }
    while(oprstk.top!=-1)
    {
        pre[j++] = pop(&oprstk);
    }
    pre[j] = '\0';
}

void main()
{
    char infix[20] , prefix[20];
    stk s;
    int i;
    s.top = -1;
    printf("Enter infix expression\n");
    scanf("%s",infix);
    strcpy(infix,strrev(infix));
    for(int i=0;i<strlen(infix);i++)
    {
    if(infix[i]==')')
        infix[i] = '(';
    else if(infix[i]=='(')
        infix[i] = ')';
    }
    infix_pre(infix,prefix);
    strcpy(prefix,strrev(prefix));
    printf("Prefix expression  %s",prefix);
}
