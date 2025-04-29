#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

// void changeLength (struct Rectangle *p, int l) {
//     p->length = p->length+l;
// }

struct Rectangle *fun()
{
    struct Rectangle *p;
    p = new Rectangle;
    // p = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    p->length = 15;
    p->breadth = 10;
    return p;
}
int main()
{
    // struct Rectangle r = {10,5};
    // changeLength(&r, 20);

    // cout<< r.length<<endl;

    struct Rectangle *ptr = fun();
    cout << ptr->length;

    return 0;
}