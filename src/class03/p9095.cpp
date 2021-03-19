#include <cstdio>

int dp(int n, int *cache)
{
    if (n <= 0)
        return 0;
    if (cache[n] != 0)
        return cache[n];
    int ret = 0;
    if (n == 1)
        ret = 1;
    else if (n == 2)
        ret = 2;
    else if (n == 3)
        ret = 4;
    else
        ret = dp(n - 1, cache) + dp(n - 2, cache) + dp(n - 3, cache);
    return cache[n] = ret;
}

void oneTwoThree(void)
{
    int n = 0;
    scanf("%d", &n);
    printf("%d\n", dp(n, new int[n + 1]()));
    return;
}

int main(void)
{
    int t = 0;
    scanf("%d", &t);
    for (int loop = 0; loop < t; loop++)
        oneTwoThree();
    return 0;
}