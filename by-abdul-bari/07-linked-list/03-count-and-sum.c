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

int Rcount( struct Node *p)
{
    if(p!=NULL)
        return Rcount( p->next) + 1;
    else 
        return 0;
}

int sum ( struct Node *p)
{
    int sum = 0 ;
    while ( p!=NULL)
    {
        sum = sum + p->data;
        p=p->next;
    }
    return sum;
}

int Rsum( struct Node *p)
{
    if(p==NULL)
        return 0;
    else 
        return Rsum(p->next)+p->next;
}

int main ()
{
    int A[] = { 3, 5, 7, 10 , 15};

    create(A, 5);
    printf("Sum is %d\n\n", Rsum(first));
    return 0;
}