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

    for ( i=1; i<n; i ++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        t->prev=last;
        last->next=t;
        last=t;
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

int Delete(struct Node *p, int index)
{
    struct Node *q;
    int x= -1, i;

    if( index < 1 || index> Length(p))
        return 0;
    
    if (index == 1)
    {
        first= first->next;
        if (first) first->prev = NULL;

        x=p->data;
        free(p);
    }
    else
    {
        for (i=0; i< index -1; i++)
            p=p->next;
        p->prev->next = p->next;
        if( p->next) 
            p->next->prev = p->prev;
        x=p->data;
        free(p);
    }

    return x;
}

void Display(struct Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    int A[] = {3, 4, 5};

    Create(A, 1);
    printf("value deleted is %d \n",Delete(first, 2));
    Display(first);

    return 0;
}