#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int *p;
    p = new int [2];
    p[0] = 1; p[2] = 12;

    for (int i=0; i<5; i++)
    cout<<p[i]<<endl;

    // when you dynamically allocated memory you should delete the allocated memory 
    // free(p); in c lang
    delete [] p;
    return 0;

}
