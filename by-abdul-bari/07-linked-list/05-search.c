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

struct Node* search( struct Node* p, int key)
{
    while (p)
    {
        if(key == p-> data)
            return p;
        p=p->next;
    }
    return NULL;
}

struct Node* Rsearch( struct Node* p, int key)
{
    if (p== NULL)
        return NULL;
    if (key == p->data)
        return p;
    return Rsearch( p->next, key);
}

struct Node* MTHsearch( struct Node* p, int key)
{
    struct Node *q;
    while (p)
    {
        if( key == p-> data)
        {
            q->next=p->next;
            p->next= first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

int main ()
{
    struct Node *temp;
    int A[] = { 3, 5, 7, 10 , 15};

    create(A, 5);
    temp= search(first , 25);

    if(temp)
        printf("Key is Found %d", temp->data);
    else 
        printf("Key is not found");
    return 0;
}