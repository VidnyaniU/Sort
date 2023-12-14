#include <stdio.h>

void insertionS(int *arr, int length)
{
    int i, j, key;

    for (i = 0; i < length; i++)
    {
        key = arr[i];
        j = i - 1;

        // move the elements to the right until key <= element
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int arr[] = {23, 65, 21, 2, 6};
    int length = sizeof(arr) / sizeof(arr[0]);

    insertionS(arr, length);

    printf("Sorted array : ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}