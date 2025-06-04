#include <stdio.h>
#include <string.h>

struct Array {
    char A[10];
    int length;
    int size;
};

int ChangeCase(char arr[]) {
    int i;
    for(i=0;arr[i]!='\0';i++)
    {
        arr[i] = arr[i] + 32;
    }
    printf("%s", arr);
    return 0;
}


int main() {
    int r;
    char s[] = "WELCOME";
    ChangeCase(s);

    return 0;
}