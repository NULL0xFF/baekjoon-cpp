#include <cstdio>
#include <algorithm>
#include <vector>

int divideCables(std::vector<int> &cables, int length)
{
    int totalCables = 0;
    for (auto it : cables)
        totalCables = totalCables + (it / length);
    return totalCables;
}
int maxLength(std::vector<int> &cables, int count, int left, int right)
{
    if (left == right)
        return left;
    int mid = (left + right) / 2;
    int midCount = divideCables(cables, mid);
    if (midCount > count)
        return maxLength(cables, count, mid + 1, right);
    else if (midCount < count)
        return maxLength(cables, count, left, mid - 1);
    else
    {
        return left;
    }
}

int main(void)
{
    std::vector<int> cables;
    int k = 0, n = 0;

    // Input
    scanf("%d %d", &k, &n);
    for (int loop = 0, input = 0; loop < k; loop++)
    {
        scanf("%d", &input);
        cables.push_back(input);
    }

    // Sort in Ascending Order
    std::sort(cables.begin(), cables.end());

    // Algorithm (Binary Search)
    printf("%d\n", maxLength(cables, n, 1, cables.at(0)));
    return 0;
}