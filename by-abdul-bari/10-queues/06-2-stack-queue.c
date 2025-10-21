#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int stack1[SIZE], stack2[SIZE];
int top1 = -1, top2 = -1;

void push1(int x) { stack1[++top1] = x; }
int pop1() { return stack1[top1--]; }

void push2(int x) { stack2[++top2] = x; }
int pop2() { return stack2[top2--]; }

int isEmpty1() { return top1 == -1; }
int isEmpty2() { return top2 == -1; }

int isFull() { return top1 == SIZE - 1; }

/* Queue Enqueue: push into stack1 */
void enqueue(int x)
{
    if (isFull())
        printf("Queue is Full\n");
    else
        push1(x);
}

/* Move all elements from stack1 to stack2 */
void transfer()
{
    while (!isEmpty1())
        push2(pop1());
}

/* Queue Dequeue: pop from stack2 (if empty, transfer first) */
int dequeue()
{
    if (isEmpty2())
    {
        if (isEmpty1())
        {
            printf("Queue is Empty\n");
            return -1;
        }
        transfer();
    }
    return pop2();
}

/* Queue Front: peek front element */
int front()
{
    if (isEmpty2())
    {
        if (isEmpty1())
        {
            printf("Queue is Empty\n");
            return -1;
        }
        transfer();
    }
    return stack2[top2];
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("dequeue: %d\n", dequeue()); // 10
    printf("front: %d\n", front());     // 20

    enqueue(40);

    printf("dequeue: %d\n", dequeue()); // 20
    printf("dequeue: %d\n", dequeue()); // 30
    printf("dequeue: %d\n", dequeue()); // 40

    return 0;
}
