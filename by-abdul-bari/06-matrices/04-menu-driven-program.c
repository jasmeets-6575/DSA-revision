#include <stdio.h>
#include <stdlib.h>

int main() {
    int *A, i, j, n, ch, x;

    printf("Enter Dimension: ");
    scanf("%d", &n);

    A = (int *)malloc(n * sizeof(int));

    do
    {
        printf("\nMENU\n");
        printf("1. Enter Diagonal Elements\n");
        printf("2. Get Element (i, j)\n");
        printf("3. Set Element (i, j, x)\n");
        printf("4. Display Matrix\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter %d diagonal elements:\n", n);
                for(i = 1; i <= n; i++)
                    scanf("%d", &A[i-1]);
                break;

            case 2:
                printf("Enter Indices i and j: ");
                scanf("%d%d", &i, &j);
                if (i == j) printf("%d\n", A[i-1]);
                else printf("0\n");
                break;

            case 3:
                printf("Enter row, col and element (i j x): ");
                scanf("%d%d%d", &i, &j, &x);
                if(i == j) A[i-1] = x;
                else printf("Only diagonal elements can be set in diagonal matrix.\n");
                break;

            case 4:
                for(i = 1; i <= n; i++)
                {
                    for(j = 1; j <= n; j++)
                    {
                        if(i == j) printf("%d ", A[i-1]);
                        else printf("0 ");
                    }
                    printf("\n");
                }
                break;

            case 5:
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (ch != 5);

    free(A);
    return 0;
}
