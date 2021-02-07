#include <cstdio>

// TODO reduce memory usage
int *mergeSort(int *array, int size)
{
    // Recursion Escape
    if (size <= 1)
        return array;

    int mid = size / 2;

    // Recursion
    int *leftArr = new int[mid]();
    for (int index = 0; index < mid; index++)
        leftArr[index] = array[index];
    leftArr = mergeSort(leftArr, mid);
    int *rightArr = new int[size - mid]();
    for (int index = mid; index < size; index++)
        rightArr[index - mid] = array[index];
    rightArr = mergeSort(rightArr, (size - mid));

    // Merge
    int *mergedArr = new int[size]();
    int leftIndex = 0, rightIndex = 0, mergedIndex = 0;
    while (true)
    {
        // Escape
        if (leftIndex == mid)
        {
            // Right Array Leftover
            while (rightIndex != (size - mid))
            {
                mergedArr[mergedIndex] = rightArr[rightIndex];
                mergedIndex++;
                rightIndex++;
            }
            break;
        }
        else if (rightIndex == (size - mid))
        {
            // Left Array Leftover
            while (leftIndex != mid)
            {
                mergedArr[mergedIndex] = leftArr[leftIndex];
                mergedIndex++;
                leftIndex++;
            }
            break;
        }

        // Compare elements
        if (leftArr[leftIndex] > rightArr[rightIndex])
        {
            mergedArr[mergedIndex] = rightArr[rightIndex];
            mergedIndex++;
            rightIndex++;
        }
        else
        {
            mergedArr[mergedIndex] = leftArr[leftIndex];
            mergedIndex++;
            leftIndex++;
        }
    }

    // Return
    return mergedArr;
}

int main(void)
{
    int *nArr = nullptr;
    int n = 0;
    scanf("%d", &n);
    nArr = new int[n]();
    for (int loop = 0; loop < n; loop++)
        scanf("%d", &nArr[loop]);

    // Sort nArr
    nArr = mergeSort(nArr, n);

    // Print
    for (int loop = 0; loop < n; loop++)
        printf("%d\n", nArr[loop]);

    return 0;
}