#include <stdio.h>

int fun(int n)
{   
    if(n > 0)
    {
        printf("%d", n);
        return fun(n - 1);
    }
    return 0;
}

int main () {
    fun(3);
    return 0;
}

// 3211211;