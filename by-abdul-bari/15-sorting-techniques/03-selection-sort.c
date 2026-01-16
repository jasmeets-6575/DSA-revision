#include <stdio.h>

void swap(int *num1 , int *num2)
{
    int temp;
    temp=*num1;
    *num1=*num2;
    *num2=temp;
}

void Selection(int A[], int n)
{
    int i, j, k;
    for(i=0; i<n-1;i++)
    {
        for(j=k=i; j<n; j++)
        {
            if(A[j] < A[k])
                k=j;
        }
        if (k != i)
            swap(&A[i], &A[k]);
    }
}

int main()
{
    int A[] = {13,7,9,10,6,5,12,4,11,2}, n= 10, i;
    Selection(A, n);

    for(i=0; i<10; i++)
        printf("%d ", A[i]);

    return 0;
}