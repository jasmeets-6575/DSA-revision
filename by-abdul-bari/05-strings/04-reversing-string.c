#include <stdio.h>
#include <string.h>

struct Array {
    char A[10];
    int length;
    int size;
};

int Reversing(char arr[]) {
    int i,j;
    char temp;
    
    for (j = 0; arr[j] != '\0'; j++) { }  
    j = j - 1;                            

    for (i = 0; i < j; i++, j--)          
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    printf("%s\n", arr);

    return 0;
}


int main() {
    int r;
    char s[] = "PYTHON";
    Reversing(s);

    return 0;
}