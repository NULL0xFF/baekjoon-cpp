#include <cstdio>

int tiling(int n, int *cache)
{
    if (n <= 0)
        return 0;
    if (cache[n] != 0)
        return cache[n];
    int ret = 0;
    if (n == 1)
        ret = 1;
    else if (n == 2)
        ret = 3;
    else
        ret = tiling(n - 1, cache) + (tiling(n - 2, cache) * 2);
    return cache[n] = ret % 10007;
}

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    printf("%d\n", tiling(n, new int[n + 1]()));
    return 0;
}