#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
} * first = NULL , *second = NULL, *third = NULL;

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

void create2 ( int A[], int n)
{
    int i;
    struct Node *temp, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next= NULL;
    last = second;

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

void display(struct Node*p)
{
    while (p!= NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
}

void Concat (struct Node*p, struct Node *q)
{
    third =p;
    
    while(p->next != NULL)
        p=p->next;
    
    p->next = q;
}

void Merge (struct Node *p, struct Node *q)
{
    struct Node *last;
    
    if(p->data < q->data)
    {
        third=last=p;
        p=p->next;
        third->next= NULL;
    }
    else 
    {
        third=last=q;
        q=q->next;
        third->next=NULL;
    }

    while (p && q)
    {
        if (p->data < q-> data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next = NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next = NULL;
        }
    }
    if (p) last->next = p;
    if (q) last->next = q;

}

int main ()
{
    int A[] = { 3, 5, 7, 11 , 15};
    int B[] = { 4, 6, 9, 10 , 16};

    create(A, 5);
    create2(B, 5);

    // Concat(first, second);
    // display(third);

    printf("First\n");
    display(first);
    printf("\n\n");

    printf("Second\n");
    display(second);
    printf("\n\n");

    return 0;
}  