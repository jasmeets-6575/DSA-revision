#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
} * front = NULL, * rear = NULL;

void enqueueFront( int x)
{
    struct Node *t;
    t=(struct Node *) malloc(sizeof(struct Node));

    if( t== NULL)
        printf("Queue is Full\n");
    else
    {
        t->data=x;
        t->next=front;
        front =t;

        if(rear == NULL)
            rear = t;
    }
}

int dequeueFront()
{
    int x =-1 ;
    struct Node *t;

    if( front == NULL)
        printf("Queue is empty \n");
    else
    {
        t= front;
        x = t->data;
        front= front->next;
        free(t);

        if (front == NULL)
            rear = NULL;
    }
    return x;
}

void enqueueRear( int x)
{
    struct Node *t;
    t=(struct Node *) malloc(sizeof(struct Node));
    
    if( t== NULL)
    printf("Queue is Full\n");
    else
    {   
        t->data=x;
        t->next=NULL;
        if( front == NULL)
            front = rear = t;
        else{
            rear->next = t;
            rear=t;
        }
    }
}

int dequeueRear()
{
    int x =-1 ;
    struct Node *p;

    if( rear == NULL)
        printf("Queue is Empty\n");
    else if (front == rear)
    {
        x=rear->data;
        free(rear);
        front = rear = NULL;
    }
    else
    {   
        p = front;
        while ( p->next != rear)
            p=p->next;
        
            x = rear->data;
            free(rear);
            rear = p;
            rear->next = NULL;
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

int main()
{
    enqueueRear(30);
    enqueueRear(50);
    enqueueFront(10);

    display();  // 10 30 50

    printf("deqRear: %d\n", dequeueRear());   // 50
    display();  // 10 30

    printf("deqFront: %d\n", dequeueFront()); // 10
    display();  // 30

    return 0;
}