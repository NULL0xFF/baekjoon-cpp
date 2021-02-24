#include <cstdio>

int main(void)
{
    long long n = 0L, r = 1L;
    scanf("%lld", &n);
    while (true)
        if (((3 * r) * (r - 1) + 1) >= n)
            break;
        else
            r++;
    printf("%lld\n", r);
    return 0;
}