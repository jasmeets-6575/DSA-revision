#include <stdio.h>

int Insert (int H[], int index)
{
    int i=index, temp;
    temp= H[i];

    while(i>1 && temp>H[i/2])
    {
        H[i]=H[i/2];
        i=i/2;
    }
    H[i]=temp;
}

int Delete (int A[], int n)
{
    int i, j, x, temp, val;
    val = A[1];
    x=A[n];
    A[1]=A[n];

    A[n] = val;
    
    i=1;j=i*2;

    while (j<n-1 )
    {
        if(A[j+1] > A[j])
            j=j+1;
        if(A[i]< A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i=j;
            j=2*j;
        }
    }
    return val;
}

int main(void) {
    int H[] = {0, 14, 15, 5, 20, 30, 8, 40};
    int i;

    for (i = 2; i <= 7; i++) {
        Insert(H, i);
    }

    for (i = 7; i > 1; i--) {
        Delete(H, i);
    }

    for (i = 1; i <= 7; i++) {
        printf("%d ", H[i]);
    }
    printf("\n");

    return 0;
}
