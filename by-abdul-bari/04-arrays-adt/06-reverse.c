#include <stdio.h>
#include <stdlib.h>

struct Array {
    int A[10];  // Array with a fixed size of 10, stored on the stack
    int size;   // Total capacity of the array
    int length; // Current number of elements in the array
};

void Display(struct Array arr)
{
    printf("Elements are:\n");
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

void Reverse(struct Array *arr)
{
    int *B;
    int i , j;

    B = (int *)malloc(arr->length*sizeof(int));
    for (i=arr->length-1, j=0; i>=0;i--, j++)
        B[j] = arr->A[i];
    for (i=0;i>arr->length; i++)
        arr->A[i] = B[i];
}
void Reverse1(struct Array *arr)
{
    int i , j, temp;

    for (i=0 , j=arr->length -1 ; i<j; i++ , j--)
    {
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

int main()
{
    struct Array arr = {{2, 3, 4, 1, 6,7, 8, 9, 10}, 10, 9};  // Array with values and size
    
    // Reverse(&arr);
    Reverse1(&arr);
    Display(arr);

    return 0;
}
