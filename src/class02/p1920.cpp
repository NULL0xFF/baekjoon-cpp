#include <cstdio>

int stack = 0;

int *mergeSort(int *array, int size)
{
    // Recursion Escape
    if (size <= 1)
        return array;

    stack++;

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

    stack--;
    // Return
    return mergedArr;
}

int binarySearch(int *array, int size, int number)
{
    if (size < 1)
        return 0;
    if (size == 1)
        if (array[0] == number)
            return 1;
        else
            return 0;
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (number < array[mid])
            right = mid - 1;
        else if (array[mid] < number)
            left = mid + 1;
        else
        {
            return 1;
        }
    }
    return 0;
}

int main(void)
{
    int *nArr = nullptr;
    int n = 0;
    scanf("%d", &n);
    nArr = new int[n]();
    for (int loop = 0; loop < n; loop++)
        scanf("%d", &nArr[loop]);

    int *mArr = nullptr;
    int m = 0;
    scanf("%d", &m);
    mArr = new int[m]();
    for (int loop = 0; loop < m; loop++)
        scanf("%d", &mArr[loop]);

    // Sort nArr
    nArr = mergeSort(nArr, n);

    // Binary Search
    for (int loop = 0; loop < m; loop++)
        printf("%d\n", binarySearch(nArr, n, mArr[loop]));

    return 0;
}