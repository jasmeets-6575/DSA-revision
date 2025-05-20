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

int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;
    l =0;
    h= arr.length -1;

    while (l<=h)
    {
        mid = (l+h)/2;
        if(key == arr.A[mid])
            return mid;
        else if( key< arr.A[mid])
            h=mid-1;
        else 
            l = mid+1;
    }
    return -1;
}

int BinarySearchRecursive(struct Array arr, int l, int h, int key)
{
    int mid;

    if(l<=h)
    {
        mid =(l+h)/2;
        if(key == arr.A[mid])
            return mid;
        else if(key< arr.A[mid])
            return BinarySearchRecursive(arr,l , mid-1, key);
        else
            return BinarySearchRecursive(arr, mid+1, h, key);
    }
    return -1;
}


int main()
{
    struct Array arr = {{2, 3, 4, 5, 6,7, 8, 9, 10}, 10, 9};  // Array with values and size

    int r, q;
    r = BinarySearch(arr, 6);
    q = BinarySearchRecursive(arr, 0, arr.length -1, 8);
    printf("%d\n", r);
    printf("%d\n", q);
    Display(arr);

    return 0;
}
