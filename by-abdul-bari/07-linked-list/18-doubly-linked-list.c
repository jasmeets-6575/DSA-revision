#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} * first = NULL;


void Create(int A[], int n)
{
    struct Node *t, *last;
    int i;

    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->prev=first->next= NULL;
    last=first;

    for ( i=0; i<n; i ++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

void Display(struct Node*p)
{
    while (p)
    {
        printf("%d ", p->data);
        p=p->next;
    }
}

int Length( struct Node *p)
{
    int len = 0;
    while (p)
    {
        len++;
        p=p->next;
    }
    return len;
}

int main()
{
    int A[] = { 3, 5, 7, 11 , 15};

    Create(A, 5);

    printf("length is %d", Length(first));
    Display(first);

    return 0;
}