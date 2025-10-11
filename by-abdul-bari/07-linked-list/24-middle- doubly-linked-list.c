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
    first->next=first;
    first->prev=first;
    last=first;

    for ( i=1; i<n; i ++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];

        t->next=first;
        t->prev=last;

        last->next=t;
        first->prev=t;

        last=t;
    }
}

int Length(struct Node *p)
{
    int len = 0;
    if (p == NULL) return 0;

    do {
        len++;
        p = p->next;
    } while (p != first);

    return len;
}


void Display(struct Node *p)
{
    if (p == NULL) {
        printf("(empty)\n");
        return;
    }

    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != first);

    printf("\n");
}

int Middle ( struct Node *p)
{
    struct Node *q;

    p=q=first;
    
    while (q)
    {
        q = q->next;
        if(q) q=q->next;
        if(q) p=p->next;
    }

    return p->data;
}

int main()
{
    int A[] = { 3, 5, 7, 11 , 15};

    Create(A, 5);
    printf("middle Value is %d \n", Middle( first));
    Display(first);

    return 0;
}