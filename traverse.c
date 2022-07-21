#include <stdio.h>
void main()
{
    int n, i, k, LB, UB, A[10];
    printf("Aatif\n");
    printf("Enter the total number of elements of array:");
    scanf("%d", &n);
    printf("Enter the elements in the array:\n");
    for (i = 1; i <= n; i++)
    {
        printf("Element number[%d] is ", i);
        scanf("%d", &A[i]);
    }

    LB = 1;
    UB = n;
    k = LB;
    printf("\n\n");
    printf("Traversing of array is:\n");
    while (k <= UB)
    {
        printf("Element number[%d] is %d\n", k, A[k]);
        k = k + 1;
    }
}
