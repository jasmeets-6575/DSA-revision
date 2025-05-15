#include <stdio.h>
#include <stdlib.h>
    
int main() {
    int *p, *q;

    p = (int *)malloc(5*sizeof(int));
    p[0] = 1;
    p[1] = 3;
    p[2] = 5;
    p[3] = 7;
    p[4] = 9;

    for ( int i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }
    
    free(p);
    p = q;
    q = NULL;

    return 0;
}