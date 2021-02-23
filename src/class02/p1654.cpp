#include <cstdio>
#include <algorithm>
#include <vector>

long long divideCables(std::vector<long long> &cables, int length)
{
    long long totalCables = 0;
    for (auto it : cables)
        totalCables = totalCables + (it / length);
    return totalCables;
}

long long maxLength(std::vector<long long> &cables, int count, int left, int right)
{
    int mid = (left + right) / 2;
    if (left == mid || mid == right)
        return mid;
    long long midCount = divideCables(cables, mid);
    if (midCount < count)
        return maxLength(cables, count, left, mid);
    else
        return maxLength(cables, count, mid, right);
}

int main(void)
{
    std::vector<long long> cables;
    int k = 0, n = 0;

    // Input
    scanf("%d %d", &k, &n);
    {
        long long input = 0L;
        for (int loop = 0; loop < k; loop++)
        {
            scanf("%lld", &input);
            cables.push_back(input);
        }
    }

    // Sort in Ascending Order
    std::sort(cables.begin(), cables.end());

    // Algorithm (Binary Search)
    printf("%lld\n", maxLength(cables, n, 1, cables.at(0)));
    return 0;
}