#include <stdio.h>
#include <stdlib.h>

// count sort works better with small sized array
void countS(int arr[], int n)
{
    // find the maximum element in the array
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // creating a count array with size max+1 to store the count of each element
    int count[max + 1];
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    // store the count of each element in the count array
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    int j = 0;
    for (int i = 0; i <= max; i++)
    {
        for (int k = 0; k < count[i]; k++)
        {
            arr[j] = i;
            j++;
        }
    }
}

int main()
{
    int arr[] = {3, 5, 2, 1, 3, 8, 4, 6, 3};
    int length = sizeof(arr) / sizeof(arr[0]);

    countS(arr, length);

    printf("Sorted array : ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}