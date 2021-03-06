#include <cstdio>

unsigned int fibonacci(unsigned int *cache, unsigned int n)
{
    if (cache[n] != -1)
        return cache[n];
    int ret = 0;
    if (n == 0)
        ret = 0;
    else if (n == 1)
        ret = 1;
    else
        ret = fibonacci(cache, n - 1) + fibonacci(cache, n - 2);
    cache[n] = ret;
    return ret;
}

int main(void)
{
    unsigned int n = 0;
    scanf("%u", &n);
    unsigned int cache[n + 1] = {};
    for (int index = 0; index <= n; index++)
        cache[index] = -1;
    printf("%u\n", fibonacci(cache, n));
    return 0;
}