
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int isOperand( char x)
{
    if ( x== '+' || x== '-' || x== '*' || x== '/')
        return 0;
    else 
        return 1;
}

int pre(char x)
{
    if (x== '+' || x== '-' )
        return 1;
    else if ( x== '*' || x== '/')
        return 2;
    return 0;
}

char * InToPost ( char *infix)
{
    int i=0,j=0;
    char *postfix;

    long len=strlen(infix);
    postfix= (char *)malloc((len+2)*sizeof(char));

    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix[j++]=infix[i++];
        else
        {
            if(pre(infix[i]) > pre(top->data))
                push(infix[i++]);
            else
            {
                postfix[j++] = pop();
            }
        }
    }

    while (top!=NULL)
        postfix[j++] = pop();
    
    postfix[j] = '\0';
    
    return postfix;
}

int main ()
{
    char *infix = "a+b*c";

    push('#');
    char *postfix = InToPost(infix);

    printf("%s", postfix);

    return 0;
}