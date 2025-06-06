#include <stdio.h>
#include <string.h>

struct Array {
    char A[10];
    int length;
    int size;
};

int CountWords(char arr[]) {
    int i, count=1;
    for(i=0;arr[i]!='\0';i++)
    {
        if(arr[i] == 32 && arr[i-1] != 32 )
            count++;
    }
    printf("%d", count);
    return 0;
}


int main() {
    int r;
    char s[] = "HOW ARE   YOU";
    CountWords(s);

    return 0;
}