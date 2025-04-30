#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Arr
{
    int A[5];
    int n;
};

void ArrAsParams (struct Arr * p ) {
    cout<<p->A[0]<<endl<<p->n<<endl;
}

int main()
{
    struct Arr r = {{2,4,6,8,10},5};
    ArrAsParams(&r);

    cout<<endl;

    return 0;
}