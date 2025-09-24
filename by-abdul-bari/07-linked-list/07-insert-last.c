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

void insertLast( struct Node *p , int index, int x)
{
    struct Node *t, *last;
    t= (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(first == NULL)
        first=last=t;
    else
    {
        last->next=t;
        last= t;
    }
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
    int A[] = { 3, 5, 7, 10 , 15};

    create(A, 5);
    insertLast(first , 3, 10);
    display(first);
    return 0;
}