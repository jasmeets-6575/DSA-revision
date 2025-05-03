#include <iostream>
#include <stdio.h>

using namespace std;

struct Rectangle 
{
    int length;
    int breadth;
};


template <class T>
class Box{
    public:
        T data;
};

int area(struct Rectangle r)
{
    return r.length * r.breadth;
}

int perimeter(struct Rectangle r)
{
    int p;
    p = 2*(r.length + r.breadth);
    return p;
}

int main() {
    Box<int> b1;
    b1.data=10;
    Box<string> b2;
    b2.data="hello";
    struct Rectangle r = {10, 5};
    int a = area(r);
    int p = perimeter(r);


    printf("Area= %d\n perimeter= %d\n", a, p);

    return 0;
}

