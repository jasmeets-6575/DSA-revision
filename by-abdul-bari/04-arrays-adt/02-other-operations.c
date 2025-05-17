#include <stdio.h>

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

void Append(struct Array *arr, int x)
{
    if(arr->length < arr->size)
        arr->A[arr->length++] = x;
}

void Insert(struct Array *arr, int index, int x)
{   
    int i;
    if(index >= 0 && index < arr->length)
    {
        for(i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];  // Shift elements to the right
        arr->A[index] = x;  // Insert the new element
        arr->length++;
    }
}

void Delete(struct Array *arr, int index)
{
    int i;
    if(index >= 0 && index < arr->length)
    {
        for(i = index; i < arr->length - 1; i++)  // Shift elements to the left
            arr->A[i] = arr->A[i + 1];
        arr->length--;
    }
}

int main()
{
    // Initialize the array statically
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};  // Array with values and size

    // Perform delete operation (deletes element at index 0)
    Delete(&arr, 6);

    // Display the updated array
    Display(arr);

    return 0;
}
