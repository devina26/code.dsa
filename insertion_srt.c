#include <stdio.h>
int main()
{
    int i, j, count, temp, number[25];
    printf("Aatif\n");
    printf("How many numbers u are going to enter?: ");
    scanf("%d", &count);

    printf("Enter %d elements:\n", count);
    for (i = 0; i < count; i++)
        scanf("%d", &number[i]);

    for (i = 1; i < count; i++)
    {
        temp = number[i];
        j = i - 1;
        while ((temp < number[j]) && (j >= 0))
        {
            number[j + 1] = number[j];
            j = j - 1;
        }
        number[j + 1] = temp;
    }

    printf("Order of Sorted elements:\n");
    for (i = 0; i < count; i++)
        printf("%d\n", number[i]);

    return 0;
}
