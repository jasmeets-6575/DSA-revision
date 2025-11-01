#include <stdio.h>

void swap(int A[], int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int Delete(int A[], int n) {
    int x = A[0];
    A[0] = A[n - 1];

    int i = 0;
    int j = 2 * i + 1;

    while (j < n - 1) {
        if (j < n - 2 && A[j] < A[j + 1]) {
            j = j + 1;
        }

        if (A[i] < A[j]) {
            swap(A, i, j);
            i = j;
            j = 2 * i + 1;
        } else {
            break;
        }
    }

    return x;
}

void Heapify(int A[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        int k = i;
        int j = 2 * k + 1;

        while (j < n) {
            if (j + 1 < n && A[j] < A[j + 1]) {
                j = j + 1;
            }

            if (A[k] < A[j]) {
                swap(A, k, j);
                k = j;
                j = 2 * k + 1;
            } else {
                break;
            }
        }
    }
}

void PrintIntArray(const int A[], int n, const char *label) {
    printf("%s: [", label);
    for (int i = 0; i < n; i++) {
        printf("%d", A[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main(void) {
    int A[] = {5, 10, 30, 20, 35, 40, 15};
    int nA = (int)(sizeof(A) / sizeof(A[0]));

    PrintIntArray(A, nA, "A");
    Heapify(A, nA);
    PrintIntArray(A, nA, "Heapified A");
    printf("\n");

    int B[] = {5, 10, 30, 20};
    int nB = (int)(sizeof(B) / sizeof(B[0]));

    PrintIntArray(B, nB, "B");
    Heapify(B, nB);
    PrintIntArray(B, nB, "Heapified B");

    return 0;
}
