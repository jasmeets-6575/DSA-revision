#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Stack
{
    int size;
    int top;
    struct Node **S;
};

void StackCreate(struct Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->S = (struct Node **)malloc(st->size * sizeof(struct Node *));
}

void push(struct Stack *st, struct Node *x)
{
    if (st->top == st->size - 1)
        printf("Stack is Full\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

struct Node *pop(struct Stack *st)
{
    struct Node *x = NULL;

    if (st->top == -1)
        printf("Stack is Empty\n");
    else
    {
        x = st->S[st->top];
        st->top--;
    }

    return x;
}

int isEmptyStack(struct Stack st)
{
    return st.top == -1;
}

struct Node *stackTop(struct Stack st)
{
    if (st.top == -1)
        return NULL;

    return st.S[st.top];
}

#endif