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

void insert( struct Node *p , int index, int x)
{
    struct Node *t;
    int i;
    if(index< 0 || index > count(p))
        return;

    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index == 0)
    {
        t->next = first;
        first = t;
    }
    else 
    {
        for (i=0; i<index-1;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next= t; 
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
    insert (first , 3, 10);
    display(first);
    return 0;
}