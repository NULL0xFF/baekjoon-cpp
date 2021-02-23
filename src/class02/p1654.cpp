#include <cstdio>
#include <algorithm>
#include <vector>

long long divideCables(std::vector<long long> &cables, long long length)
{
    long long totalCables = 0;
    for (auto it : cables)
        totalCables = totalCables + (it / length);
    return totalCables;
}

long long maxLength(std::vector<long long> &cables, long long left, long long right, long long target)
{
    if(left > right)
        return right;
    long long mid = (left + right) / 2;
    long long midCount = divideCables(cables, mid);
    if (midCount < target)
        return maxLength(cables, left, mid - 1, target);
    else
        return maxLength(cables, mid + 1, right, target);
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
    printf("%lld\n", maxLength(cables, 1, cables.back(), n));
    return 0;
}