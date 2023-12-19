#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionS(int *arr, int length)
{
    int i, j;
    for (i = 0; i < length-1; i++)
    {
        int minIdx = i;

        for (j = i + 1; j < length; i++)
        {
            if (arr[j] < arr[minIdx]) // check if any small number lies before minIdx
            {
                minIdx = j;
                swap(&arr[minIdx], &arr[i]);
            }
        }
    }
}
int main()
{
    int arr[] = {23, 65, 21, 2, 6,43};
    int length = sizeof(arr) / sizeof(arr[0]);

    selectionS(arr, length);

    printf("Sorted array : ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
