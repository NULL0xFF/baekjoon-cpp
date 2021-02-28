#include <cstdio>
#include <vector>
#include <algorithm>

unsigned long long getLogs(std::vector<unsigned long long> &forest, unsigned long long height)
{
    unsigned long long totalLength = 0L;
    for (auto it : forest)
        totalLength = totalLength + (it > height ? it - height : 0);
    return totalLength;
}

unsigned long long maxHeight(std::vector<unsigned long long> &forest, unsigned long long left, unsigned long long right, unsigned long long target)
{
    if (left > right)
        return right;
    unsigned long long mid = (left + right) / 2;
    unsigned long long totalLength = getLogs(forest, mid);
    if (totalLength < target)
        return maxHeight(forest, left, mid - 1, target);
    else
        return maxHeight(forest, mid + 1, right, target);
}

int main(void)
{
    std::vector<unsigned long long> forest;
    unsigned long long n = 0, m = 0, max = 0;
    scanf("%llu %llu", &n, &m);
    for (unsigned long long loop = 0, input = 0; loop < n; loop++)
    {
        scanf("%llu", &input);
        forest.push_back(input);
    }
    std::sort(forest.begin(), forest.end());
    printf("%llu\n", maxHeight(forest, 1, forest.back(), m));
    return 0;
}