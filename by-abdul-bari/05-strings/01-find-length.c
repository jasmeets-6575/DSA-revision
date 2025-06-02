#include <stdio.h>
#include <string.h>

struct Array {
    char A[10];
    int length;
    int size;
};

void Display(struct Array arr)
{
    printf("Elements are:\n");
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

int Find(char arr[]) {
    int i, length =0;
    for(i=0;;i++)
    {
        length++;
        if( arr[i]== '\0')
            break;
    }
    return length - 1;
}


int main() {
    int r;
    char s[] = "WELCOME";
    printf("%d\n", Find(s));
    return 0;
}