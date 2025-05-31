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

int MaxMin(struct Array *arr)
{
    int i , min, max;
    min =arr->A[0];
    max= arr->A[0];
    for(i=0; i<arr->length -1; i++)
    {
        if(arr->A[i] > max){
            max = arr->A[i];
        } 
        else if (arr->A[i] < min){
            min = arr->A[i];
        }
    }
    printf("%d %d" , min, max);
    return 0;
}

int main()
{
    int r;
    struct Array arr1 = {{5,8,3,9,6,2,10,7,-1,4}, 10, 10};  
    struct Array arr2 = {{8,9,11,11,15,16,16,16}, 10, 8};  
    // &r = Missing(&arr2);
    printf("Element no. %d \n", MaxMin(&arr1));
    Display(arr2);


    return 0;
}
