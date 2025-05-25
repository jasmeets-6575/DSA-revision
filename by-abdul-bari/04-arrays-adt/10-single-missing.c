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

int Missing(const struct Array *arr)
{
    for (int i = 0; i < arr->length; i++)
    {
        int expected = i + 1;
        if (arr->A[i] != expected)
            return expected;
    }
    return -1;
}

int Missing2(struct Array *arr)
{
    if (arr->length == 0) return -1;

    int start = arr->A[0];
    int end   = arr->A[arr->length - 1];

    int expected = (end * (end + 1)) / 2 - ((start - 1) * start) / 2;

    int actual = 0;
    for (int i = 0; i < arr->length; i++)
        actual += arr->A[i];

    return expected - actual;
}


int Missing3(struct Array *arr)
{
    int i, diff;
    diff = arr->A[0];
    for(i=0; i<arr->length; i++)
    {
        if( arr->A[i] - i != diff)
            return i + diff;
    }
    return -1;
}

int main()
{
    int r;
    struct Array arr1 = {{1,2,3,4,6,7,8}, 10, 7};  
    struct Array arr2 = {{8,9,10,11,12,13,15}, 10, 7};  
    r = Missing3(&arr2);
    printf("Element no. %d \n", r);
    Display(arr2);


    return 0;
}
