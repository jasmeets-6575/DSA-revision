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

void insert ( struct Node *p, int x, int index)
{
    struct Node *t; 
    int i;

    if(index < 0 || index > Length(p))
        return;

    t=(struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if( index == 0)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev= NULL;
        t->next=first;
        first->prev = t;
        first = t;
    }
    else 
    {
        for (i=0; i< index -1; i++)
            p=p->next;
            
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data = x;

        t->prev= p;
        t->next=p->next;
        
        if(p->next)
            p->next->prev= t;

        p->next=t;     
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