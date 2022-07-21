#include <stdio.h>
int main()
{
    int arr[50], size, i, j, temp;
    printf("Enter array size:\n");
    scanf("%d", &size);
    printf("Enter %d array elements:\n", size);
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    j = i - 1; // now j will point to the last element
    i = 0;     //  and i will be point to the first element
    while (i < j)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    printf("\nReverse of the Array is:\n");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}
