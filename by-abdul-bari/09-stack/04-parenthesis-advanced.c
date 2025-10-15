#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    char data;
    struct Node *next;
} * top = NULL;

void push( char x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));

    // check heap is full by 
    if(t == NULL)
        printf("stack(heap) is full");
    else
    {
        t->data = x;
        t->next= top;
        top=t;
    }
}

char pop ()
{
    struct Node *t;
    char x = -1;

    if(top == NULL)
        printf("Stack is Empty");
    else 
    {
        t=top;
        top = top->next;
        x= t->data;
        free(t);
    }
    return x;
}


void display ()
{
    struct Node *p;
    p=top;
    while(p != NULL)
    {
        printf("%c ", p->data);
        p=p->next;
    }
    printf("\n");
}

void resetStack()
{
    while (top != NULL)
        pop();
}

int isMatchingPair(char open, char close)
{
    return (open == '(' && close == ')') ||
        (open == '{' && close == '}') ||
        (open == '[' && close == ']');
}
int isBalanced2( char *exp)
{
    int i;

    for( i=0; exp[i] !='\0'; i++)
    {
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
            push(exp[i]);
        else  if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
        {
            if (top == NULL)
            {
                resetStack();
                return 0;
            }
            char open = pop();

            if (!isMatchingPair(open, exp[i]))
            {
                resetStack();
                return 0;
            }
        }
    }

    if (top == NULL)
        return 1;

    resetStack();
    return 0;
}

int main ()
{
    char *exp1 = "((a+b)*(c-d))";
    char *exp2 = "{[a-b](c*d)}";
    char *exp3 = "{[a-b](c*d)]}"; 

    printf("exp1: %d\n", isBalanced2(exp1));
    printf("exp2: %d\n", isBalanced2(exp2));
    printf("exp3: %d\n", isBalanced2(exp3));
    return 0;
}