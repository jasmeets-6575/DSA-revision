#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main () {
    // in Stack

    struct Rectangle r = {10, 5};
    cout<<r.length<<endl;
    cout<<r.breadth<<endl;

    Rectangle *p=&r;
    cout<<p->length<<endl;
    cout<<p->breadth<<endl;

    // In heap

    // Rectangle *p;
    // p = (struct Rectangle *)malloc(sizeof(Rectangle));

    // p->length= 15;
    // p->breadth=7;

    // printf("%d", p->length);
    // printf("%d", p->breadth);
    
    return 0;
}