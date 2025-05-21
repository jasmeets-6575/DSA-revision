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

int Get(struct Array arr, int index)
{
    if( index > 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

int Set(struct Array *arr, int index, int val)
{
    return arr->A[index] = val;
}

int Max(struct Array arr)
{
    int i, maxNum = 0;
    for (i=0; i< arr.length; i++ )
    {
        if( arr.A[i] > maxNum )
            maxNum = arr.A[i];
        else if (arr.A[i] < maxNum )
            continue;
    }
    return maxNum;
}

int Min (struct Array arr)
{
    int i, minNum;
    minNum = arr.A[0];
    for(i=1; i< arr.length; i++)
    {
        if( arr.A[i] < minNum )
            minNum = arr.A[i];
    }
    return minNum;
}
int Sum (struct Array arr)
{
    int s =0;
    int i;
    for(i=0; i< arr.length; i++)
        s+=arr.A[i];

    return s;
}

float Avg(struct Array arr)
{
    return (float)Sum(arr)/arr.length;
}

int main()
{
    struct Array arr = {{2, 3, 4, 1, 6,7, 8, 9, 10}, 10, 9};  // Array with values and size

    int r, q, s, t;
    r = Get(arr, 6);
    q = Set(&arr, 4 ,5);
    s = Max(arr);
    t = Min(arr);
    // printf("%d\n", r);
    // printf("%d\n", q);
    // printf("%d\n", s);
    printf("%d\n", t);
    Display(arr);

    return 0;
}
