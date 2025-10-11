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

void Insert (struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    t=(struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if( index < 0 || index > Length(p))
        return;

    if(first == NULL)
    {
        t->next = t;
        t->prev = t;
        first =t;
        return;
    }

    if(index == 0)
    {
        t->next = first;
        t->prev = first->prev;

        first -> prev -> next = t;
        first -> prev = t;
        first = t;
        return;
    }
    else
    {
        for ( i=0; i< index -1; i++)
            p = p->next;

        t->next = p->next;
        t->prev = p;

        p->next->prev = t;
        p->next = t;
    }
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

int main()
{
    int A[] = { 3, 5, 7, 11 , 15};

    Create(A, 5);

    printf("length is %d\n", Length(first));
    Insert(first , 4, 4);
    Display(first);

    return 0;
}