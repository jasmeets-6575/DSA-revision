#include <stdio.h>

int Sum(n)
{
    if( n == 0 || n == 1)
        return 1;
    else 
        return Sum(n-1) + n;
}

int Fac(n)
{
    if( n == 0 || n == 1)
        return 1;
    else 
        return n * fac(n-1);
}
int Po(m, n)
{
    if (n % 2 ==0 )
        return pow( m * m, n/2);
    if (n % 2 != 0 )
        return m * pow(m * m , (n-1)/2);
}

int funT(int n)
{
    if( n == 0 || n == 1)
        return 1;
    else 
        return Sum(Po(n-1,n-1)/ Fac(n-1)) + Po(n,n)/ Fac(n) ;
}

int main()
{
    int r;
    r = funT(4);
    printf("%d\n", r);
    return 0; 
}