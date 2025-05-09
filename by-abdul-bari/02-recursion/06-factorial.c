#include <stdio.h>

int funcFact( int n){
    if ( n < 0 || n == 1 || n == 0 )
        return 1;
    else 
        return funcFact( n - 1) * n;
}

int main() {
    int r; 
    r = funcFact(5);
    printf("%d\n", r);
    
    return 0;
}