#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
} * front = NULL, * rear = NULL;

void enqueue( int x)
{
    struct Node *t;
    t=(struct Node *) malloc(sizeof(struct Node));

    if( t== NULL)
        printf("Queue is FUll\n");
    else
    {
        t->data=x;
        t->next=NULL;

        if(front == NULL)
            front = rear = t;
        else 
        {
            rear->next = t;
            rear= t;
        }
    }
}

int dequeue()
{
    int x =-1 ;
    struct Node *t;

    if( front == NULL)
        printf("Queue is empty \n");
    else
    {
        t= front;
        x = front->data;
        front= front->next;
        free(t);
    }
    return x;
}

void display()
{
    struct Node *p= front;
    while(p)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

int main ()
{
    struct Node q;

    enqueue(30);
    enqueue(50);

    display();
    printf("DEQUEUE value is %d \n", dequeue());
    display();

    return 0;
}