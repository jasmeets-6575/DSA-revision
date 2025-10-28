#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

struct Node *root = NULL;

void treeCreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("Enter root value \n");
    scanf("%d", &x);

    root=(struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while( !isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter left child of %d : ", p->data);
        scanf("%d", &x);
        if(x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        printf("Enter right child of %d : ", p->data);
        scanf("%d", &x);
        if(x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void preorder( struct Node *p)
{
    if(p)
    {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder( struct Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

void postorder( struct Node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}

void IPreorder(struct Node *p)
{
    struct Stack stk;
    StackCreate(&stk, 100);

    while(p || !isEmptyStack(stk))
    {
        if(p)
        {
            printf("%d ", p->data);
            push(&stk, p);
            p=p->lchild;
        }
        else
        {
            p=pop(&stk);
            p=p->rchild;
        }
    }
}

void IInorder(struct Node *p)
{
    struct Stack stk;
    StackCreate(&stk, 100);

    while(p || !isEmptyStack(stk))
    {
        if(p)
        {
            push(&stk, p);
            p=p->lchild;
        }
        else
        {
            p=pop(&stk);
            printf("%d ", p->data);
            p=p->rchild;
        }
    }
}

void IPostorder(struct Node *p)
{
    struct Stack s1, s2;
    struct Node *t;

    if (p == NULL) return;

    StackCreate(&s1, 100);
    StackCreate(&s2, 100);

    push(&s1, p);

    while (!isEmptyStack(s1))
    {
        t = pop(&s1);
        push(&s2, t);

        if (t->lchild)
            push(&s1, t->lchild);

        if (t->rchild)
            push(&s1, t->rchild);
    }

    while (!isEmptyStack(s2))
    {
        t = pop(&s2);
        printf("%d ", t->data);
    }
}

void LevelOrder(struct Node *root)
{
    struct Queue q;
    create(&q, 100);

    printf("%d ", root->data);
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        root = dequeue(&q);
        if(root->lchild)
        {
            printf("%d ", root->lchild->data);
            enqueue(&q, root->lchild);
        }
        if(root->rchild)
        {
            printf("%d ", root->rchild->data);
            enqueue(&q, root->rchild);
        }
    }
}

int count (struct Node *root)
{
    if(root)
        return count(root->lchild) + count(root->rchild) + 1;
    return 0;
}

int height (struct Node *root)
{
    int x = 0, y=0;
    if(root==0)
        return 0;
    x = height(root->lchild);
    y = height(root->rchild);

    if(x>y)
        return x + 1;
    else
        return y + 1;
}

int countLeaf(struct Node *root)
{
    if (root == NULL)
        return 0;

    if (root->lchild == NULL && root->rchild == NULL)
        return countLeaf(root->lchild) + countLeaf(root->rchild) + 1;

    return countLeaf(root->lchild) + countLeaf(root->rchild);
}

int countDeg1(struct Node *root)
{
    if (root == NULL)
        return 0;

    if ((root->lchild != NULL && root->rchild == NULL) ||
        (root->lchild == NULL && root->rchild != NULL))
        return countDeg1(root->lchild) + countDeg1(root->rchild) + 1;

    return countDeg1(root->lchild) + countDeg1(root->rchild);
}

int countDeg2(struct Node *root)
{
    if (root == NULL)
        return 0;

    if (root->lchild != NULL && root->rchild != NULL)
        return countDeg2(root->lchild) + countDeg2(root->rchild) + 1;

    return countDeg2(root->lchild) + countDeg2(root->rchild);
}

int countDegGT0(struct Node *root) //(non-leaf / internal)
{
    if (root == NULL)
        return 0;

    if (root->lchild != NULL || root->rchild != NULL)
        return countDegGT0(root->lchild) + countDegGT0(root->rchild) + 1;

    return countDegGT0(root->lchild) + countDegGT0(root->rchild);
}

int main()
{
    treeCreate();
    printf("Pre order\n ");
    IPreorder(root);
    printf("in order \n ");
    IInorder(root);
    printf("post order \n ");
    IPostorder(root);
    printf("Level order \n ");
    LevelOrder(root);
    printf("Count : %d \n", count(root));
    printf("Height : %d \n", height(root));

    return 0;
}