#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    printf("Elements are:\n");
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

int main()
{
    struct Array arr;
    int n;

    printf("Enter size of array: ");
    scanf("%d", &arr.size);

    arr.A = (int *)malloc(arr.size * sizeof(int));
    if (arr.A == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter number of elements (<= %d): ", arr.size);
    scanf("%d", &n);

    if (n > arr.size) {
        printf("Error: n cannot be greater than size.\n");
        free(arr.A);
        return 1;
    }

    printf("Enter all elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr.A[i]);

    arr.length = n;

    Display(arr);

    free(arr.A);
    return 0;
}
