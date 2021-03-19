#include <cstdio>

typedef long long ll;

ll fibonacci(ll *cache, ll n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    if (cache[n] == 0)
        cache[n] = fibonacci(cache, n - 1) + fibonacci(cache, n - 2);
    return cache[n];
}

int main(void)
{
    ll n = 0;
    scanf("%lld", &n);
    ll cache[n + 1] = {};
    printf("%lld\n", fibonacci(cache, n));
    return 0;
}