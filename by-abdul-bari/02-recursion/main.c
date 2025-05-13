#include <stdio.h>

int Fib (int n)
{
    if ( n == 0 ) 
        return 0; 
    if ( n == 1 ) 
        return 1;
    else 
        return Fib( n - 2) + Fib( n -1);

}

int main() 
{
    int r;
    r = Fib(7);
    printf("%d\n", r);
    return 0;
}