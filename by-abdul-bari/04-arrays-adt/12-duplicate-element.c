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

int Duplicate(struct Array *arr)
{
    int i , same;
    same=0;
    for(i=0; i<arr->length -1; i++)
    {
        if(arr->A[i] == arr->A[i+1] && arr->A[i] != same)
        {
            printf("%d\n", arr->A[i]);
            same = arr->A[i];
        }
    }
    return 0;
}

int main()
{
    int r;
    struct Array arr1 = {{1,2,3,4,6,7,8}, 10, 7};  
    struct Array arr2 = {{8,9,11,11,15,16,16,16}, 10, 8};  
    // &r = Missing(&arr2);
    printf("Element no. %d \n", Duplicate(&arr2));
    Display(arr2);


    return 0;
}
