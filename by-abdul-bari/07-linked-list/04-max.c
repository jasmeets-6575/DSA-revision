#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


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

int max( struct Node *p)
{
    int max=INT32_MIN;

    while(p)
    {
        if(p->data > max) 
            max= p->data;
        p=p->next;
    }
    return max;
}

int Rmax(struct Node *p)
{
    if (p == NULL)
        return INT_MIN;

    int x = Rmax(p->next);

    return (x > p->data) ? x : p->data;
}


int main ()
{
    int A[] = { 3, 5, 7, 10 , 15};

    create(A, 5);
    printf("Sum is %d\n\n", max(first));
    return 0;
}