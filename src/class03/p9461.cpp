#include <cstdio>

typedef unsigned int ui;
typedef unsigned long long ull;

ull series(ui n, ull *cache = nullptr)
{
    bool isCached = false;
    if (isCached = (cache != nullptr))
        if (cache[n] != 0)
            return cache[n];
    ull ret = 0;
    if (n <= 3)
        ret = 1;
    else if (n <= 5)
        ret = 2;
    else
        ret = series(n - 1, cache) + series(n - 5, cache);
    if (isCached)
        cache[n] = ret;
    return ret;
}
int main(void)
{
    ui t = 0;
    scanf("%u", &t);
    for (ui loop = 0; loop < t; loop++)
    {
        ui n = 0;
        scanf("%u", &n);
        printf("%llu\n", series(n, new ull[n + 1]()));
    }
    return 0;
}