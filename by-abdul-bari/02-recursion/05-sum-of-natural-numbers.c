#include <stdio.h>

int Sum(int n)
{
    if(n==0)
        return 0;
    else 
        return Sum(n-1) + n;
}

int main() {
    int r;
    r= Sum(5);
    printf("%d\n", r);
    return 0;
}