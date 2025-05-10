#include <stdio.h>

int pow1(int m, int n)
{
    if( n == 0)
        return 1;
    else 
        return pow (m , n-1) * m;
}

// imp
int pow2 (int m , int n)
{
    if (n ==0)
        return 1;
    if (n%2 ==0 )
        return pow(m*n, n/2);
    else 
        return m*pow(m*m, (n-1)/2);
}

int main () 
{
    int r;
    r = pow1(3,2);
    printf("%d", r);

    return 0;
}