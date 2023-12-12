#include <stdio.h>
#include <stdlib.h>

FILE *ptrIn;
FILE *ptrOut;
void mergeM(int arr[], int left, int mid, int right)
{
    fprintf(ptrOut, "Entered function mergeM with arr = ");
    for (int i = 0; i < right; i++)
    {
        fprintf(ptrOut, "%d", arr[i]);
    }

    fprintf(ptrOut, "\n left = %d , mid = %d and right = %d \n", left, mid, right);
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    // left and right subarray
    int leftArr[leftSize], rightArr[rightSize];

    // copying the elements into the subarrays
    for (int i = 0; i < leftSize; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < rightSize; i++)
    {
        rightArr[i] = arr[mid + 1 + i];
    }

    int leftInd = 0;   // initial index of left subarray
    int rightInd = 0;  // initial index of right subarray
    int arrInd = left; // initial index of the actual array

    // main logic of merge sort
    while (leftInd < leftSize && rightInd < rightSize)
    {
        if (leftArr[leftInd] <= rightArr[rightInd])
        {
            arr[arrInd] = leftArr[leftInd];
            leftInd++;
        }
        else
        {
            arr[arrInd] = rightArr[rightInd];
            rightInd++;
        }
        arrInd++;
    }

    // for remaining elements of left subarray if any
    while (leftInd < leftSize)
    {
        arr[arrInd] = leftArr[leftInd];
        leftInd++;
        arrInd++;
    }
    // for remaining elements of right subarray if any
    while (rightInd < rightSize)
    {
        arr[arrInd] = rightArr[rightInd];
        rightInd++;
        arrInd++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    fprintf(ptrOut, "Entered function mergeM with arr = ");
    for (int i = 0; i < right; i++)
    {
        fprintf(ptrOut, "%d ", arr[i]);
    }
    fprintf(ptrOut, "\n left = %d  and right = %d \n", left, right);

    if (left < right)
    {
        int mid = (left + right) / 2;   // to find mid value
        mergeSort(arr, left, mid);      // recursively calling for left sub array
        mergeSort(arr, mid + 1, right); // recursively calling for right sub array
        mergeM(arr, left, mid, right);  // calling merge function for merging the subarrays
    }
}
int main()
{
    int size;
    ptrIn = fopen("sortinput.txt", "r");
    ptrOut = fopen("sortoutput.txt", "w");

    fscanf(ptrIn, "%d", &size);

    int *arr = (int *)malloc(sizeof(int) * size);

    int i = 0;
    while (fscanf(ptrIn, "%d", &arr[i]) != EOF)
    {
        i++;
    }
    mergeSort(arr, 0, size + 1);
    fprintf(ptrOut, "\n\nSorted array : ");
    for (int i = 0; i <= size; i++)
    {
        fprintf(ptrOut, "%d ", arr[i]);
    }

    fclose(ptrIn);
    fclose(ptrOut);
    return 0;
}