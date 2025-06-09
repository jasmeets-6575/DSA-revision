#include <stdio.h>
#include <string.h>

int main() {
    int r;
    char A[] = "decimal";
    char B[] = "medical";
    int i, H[26]={0};
    
    for (i = 0; A[i]!='\0'; i++)          
    {
        H[A[i] - 97] += 1;
    }
    for(i =0; B[i]!='\0'; i++)
    {
        H[A[i] - 97] -= 1;
        if( H[B[i] - 97] < 0)
        {
            printf("not anagram");
            return 0;
        }
    }
    printf("ITS anagram");

    return 0;
}