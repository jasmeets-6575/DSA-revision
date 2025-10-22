#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int pri; // smaller number = higheer priority
    struct Node *next;
} *front = NULL;

void enqueue(int x, int p)
{
    struct Node *t, *q;

    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Queue is Full\n");
        return;
    }

    t->data = x;
    t->pri = p;
    t->next = NULL;

    if(front == NULL || p < front->pri)
    {
        t->next = front;
        front = t;
    }
    else
    {
        q=front;
        while (q->next != NULL && q->next->pri <= p)
            q=q->next;
        t->next = q->next;
        q->next = t;
    }
}

int dequeue()
{
    int x = -1;
    struct Node *t;

    if(front == NULL)
        printf("Queue is Empty\n");
    else
    {
        t= front;
        x= t->data;
        front = front->next;
        free(t);
    }
    return x;
}

void display()
{
    struct Node *p = front;
    while (p)
    {
        printf("(%d, p=%d) ", p->data, p->pri);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    enqueue(10, 3);
    enqueue(20, 1);
    enqueue(30, 2);
    enqueue(40, 2);
    enqueue(50, 5);

    display();  // (20,p=1) (30,p=2) (40,p=2) (10,p=3) (50,p=5)

    printf("dequeue: %d\n", dequeue()); // 20
    printf("dequeue: %d\n", dequeue()); // 30

    display();

    return 0;
}