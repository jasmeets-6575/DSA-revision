#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

void initialize(struct Rectangle *r,int l,int b)
{
    r->length = l;
    r->breadth = b;
}

int area (struct Rectangle r1)
{
    return r1.length * r1.breadth;
}

void changeLength(struct Rectangle *r1 , int a)
{
    r1->length = r1->length + a;
}

int main()
{
    struct Rectangle r;
    initialize(&r, 10, 5);
    area(r);
    changeLength(&r, 20);
}