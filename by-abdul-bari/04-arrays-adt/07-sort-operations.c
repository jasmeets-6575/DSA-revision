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

// void Insert(struct Array *arr, int key)
// {
//     int i;
//     for(i=0; i< arr->length- 1; i++)
//     {
//         if (arr->A[i] < arr->A[i+1] && arr->A[i] > key && key < arr->A[i+1] )
//         {
//             arr->A[i] = key;
//             break;
//         }
//     }
// }
void Insert(struct Array *arr, int key)
{
    int i;
    i = arr->length;

    if(arr->length == arr->size)
        return;

    while (i>=0 && arr->A[i] > key)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = key;
    arr->length++;
}

int isSorted (struct Array arr)
{
    int i;
    for (i=0 ; i< arr.length -1; i++)
    {
        if(arr.A[i]> arr.A[i+1])
            return 0;
    }
    return 1;
}
// if the array has the alternate negative and positive values
void Rearrange ( struct Array *arr)
{
    int i, j, temp;
    i=0;
    j=arr->length-1;

    while (i<j)
    {
        while(arr->A[i]<0)i++;
        while(arr->A[i]>=0)j--;
        if(i<j)
        {
            temp = arr->A[i];
            arr->A[i] = arr->A[j];
            arr->A[j] = temp;
        }
    }
}

int main()
{
    struct Array arr = {{2, 4, 6, 8, 10,12, 14, 15, 17}, 10, 9};  // Array with values and size
    
    Insert(&arr ,11 );
    Display(arr);

    return 0;
}
