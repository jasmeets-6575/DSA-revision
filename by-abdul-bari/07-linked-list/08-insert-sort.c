#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
} * first = NULL;

void create ( int A[], int n)
{
    int i;
    struct Node *temp, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next= NULL;
    last = first;

    for (i=1; i<n; i++)
    {
        temp= (struct Node*)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

int count ( struct Node *p)
{
    int count = 0 ;
    while (p)
    {
        count ++;
        p=p->next;
    }

    return count;
}

void insertSort( struct Node *p , int x)
{
    struct Node *t, *q=NULL;
    t= (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    // check if it is first node
    if(first == NULL)
        first = t;
    else
    {
        while ( p && p->data < x)
        {
            q=p;
            p=p->next;
        }
        if( p == first)
        {
            t->next = first;
            first = t;
        }
        else 
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

void insertSort2( struct Node *p , int x)
{
    struct Node *t;
    t= (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    // check if it is first node
    if(first == NULL || x < first->data)
    { 
        t->next = first;
        first = t;
        return;
    }

    while ( p->next != NULL && p->next->data < x)
        p= p->next;

    t->next = p->next;
    p->next = t;
}

void display(struct Node*p)
{
    while (p!= NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
}

int main ()
{
    // int A[] = { 3, 5, 7, 10 , 15};

    // create(A, 5);
    // display(first);

    insertSort(first , 3);
    insertSort(first , 5);
    display(first);
    return 0;
}