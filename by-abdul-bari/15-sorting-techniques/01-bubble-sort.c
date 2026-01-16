#include <stdio.h>

void swap(int *num1 , int *num2)
{
    int temp;
    temp=*num1;
    *num1=*num2;
    *num2=temp;
}

void Bubble(int A[], int n)
{
    int i, j, flag=0;

    for(i=0; i<n-1; i++)
    {
        flag=0;
        for(j=0; j<n-i-1; j++)
        {
            if(A[j]>A[j+1])
            {
                swap(&A[j], &A[j+1]);
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}

int main()
{
    int A[] = {3,7,9,10,6,5,12,4,11,2}, n= 10, i;
    Bubble(A, n);

    for(i=0; i<10; i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
}