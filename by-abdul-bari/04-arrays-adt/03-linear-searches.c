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

void swap (int *m, int *n)
{
    int temp;
    temp = *m;
    *m = *n;
    *n = temp;
}

int LinearSearch(struct Array arr, int k)
{
    int i;
    for(i=0;i<arr.length;i++)
    {
        if(arr.A[i] == k)
            return i;
    }
    return printf("not found");
}

int LinearSearchTransposition(struct Array *arr, int k)
{
    for(int i = 0; i < arr->length; i++)
    {
        if(arr->A[i] == k)
        {
            if(i > 0)
                swap(&arr->A[i], &arr->A[i-1]);

            return i;
        }
    }
    return -1;
}

int LinearSearchMoveToHead(struct Array *arr, int k)
{
    for(int i = 0; i < arr->length; i++)
    {
        if(arr->A[i] == k)
        {
            swap(&arr->A[i], &arr->A[0]);
            return 0;
        }
    }
    return -1;
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6,7, 8, 9, 10}, 10, 9};  // Array with values and size

    int r, q, s;
    r = LinearSearch(arr, 6);
    q = LinearSearchTransposition(&arr, 5);
    s = LinearSearchMoveToHead(&arr, 9);
    printf("%d\n", r);
    printf("%d\n", q);
    printf("%d\n", s);
    Display(arr);

    return 0;
}
