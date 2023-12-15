#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleS(int *arr, int length)
{
    bool swapped;
    for (int i = 0; i < length - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped != true)
        {
            break; // array is sorted
        }
    }
}
int main()
{
    int arr[] = {23, 65, 21, 2, 6};
    int length = sizeof(arr) / sizeof(arr[0]);

    bubbleS(arr, length);

    printf("Sorted array : ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}