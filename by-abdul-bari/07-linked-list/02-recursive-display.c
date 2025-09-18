#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
} * first =NULL;

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

void recursiveDisplay( struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d", p->data);
        recursiveDisplay(p->next);
    }
}

int main ()
{
    int A[] = {3, 5, 7, 10, 15};

    create( A, 5);

    recursiveDisplay(first);

    return 0;
}