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

int Missing(struct Array *arr)
{
    int i, diff;;
    diff = arr->A[0] - 0;
    for(i=0; i<arr->length; i++)
    {
        if( arr->A[i] - i != diff)
        {   
            while ( diff < arr->A[i] -i )
            {
                printf("%d\n", i+ diff);
                diff++;
            }
        }
    }
    return 0;
}

int main()
{
    int r;
    struct Array arr1 = {{1,2,3,4,6,7,8}, 10, 7};  
    struct Array arr2 = {{8,9,11,12,15,16,17,18}, 10, 8};  
    // &r = Missing(&arr2);
    printf("Element no. %d \n", Missing(&arr2));
    Display(arr2);


    return 0;
}
