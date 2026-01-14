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

int Delete ( struct Node *p, int index)
{
    struct Node *t;

    int x = -1, i;

    if( index < 1 || index> Length(p))
        return 0;

    if (index == 1 )
    {
        p = first;
        x = first->data;
        first->prev->next = first->next;
        first->next->prev = first->prev;
        first = first->next;
        free(p);
    }
    else
    {
        for ( i=0; i< index - 1; i++)
            p=p->next;
        x = p->data;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
    }


    return x;
}

int main()
{
    int A[] = { 3, 5, 7, 11 , 15};

    Create(A, 5);
    printf("Value deleted is %d \n", Delete( first , 3));
    Display(first);

    return 0;
}