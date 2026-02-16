#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

void Insert(int key)
{
    struct Node *t = root;
    struct Node *r, *p;
    
    if(root==NULL)
    {
        p=(struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }

    while(t != NULL)
    {
        r = t;

        if(key < t->data)
            t=t->lchild;
        else if(key > t->data)
            t=t->rchild;
        else
            return;
    }

    p=(struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if(key < r->data) 
        r->lchild = p;
    else
        r->rchild = p;
}

void RInorder( struct Node *p)
{
    if(p)
    {
        RInorder(p->lchild);
        printf("%d ", p->data);
        RInorder(p->rchild);
    }
}

struct Node * Search (int key)
{
    struct Node *t=root;

    while(t!=NULL)
    {
        if(key == t->data)
            return t;
        else if ( key < t->data)
            t=t->lchild;
        else 
            t=t->rchild;
    }
    return NULL;
}

struct Node *RInsert( struct Node *p, int key)
{
    struct Node *t = NULL;

    if(p==NULL)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if(key > p->data)
        p->rchild = RInsert(p->rchild, key);
    
    return p;
}

int main ()
{
    struct Node *temp;

    // root = RInsert(root, 10);
    // RInsert(root, 5);
    // RInsert(root, 20);
    Insert(8);
    Insert(30);

    RInorder(root);
    temp = Search(20);

    if(temp!=NULL)
        printf("element %d is found\n", temp->data);
    else
        printf("Element is not found");
    
    return 0;
}