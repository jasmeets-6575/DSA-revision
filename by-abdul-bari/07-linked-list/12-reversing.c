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

void reverse1( struct Node *p)
{   
    int *A, i=0;
    struct Node *q=p;
    A=(int *)malloc(sizeof(int)*count(p));

    while(q!=NULL)
    {
        A[i] = q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL)
    {
        q->data=A[i];
        q=q->next;
        i--;
    }
}

void Reverse2(struct Node *p)
{
    struct Node *q=NULL, *r=NULL;

    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first = q;
}

void Reverse3 (struct Node *q, struct Node *p )
{
    if(p)
    {
        Reverse3(p, p->next);
        p->next = q;
    }
    else 
        first = q;
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
    int A[] = { 3, 5, 5, 7, 10 , 15};

    create(A, 5);
    removeDuplicated(first);

    // index
    delete(first , 3);
    display(first);
    return 0;
}  