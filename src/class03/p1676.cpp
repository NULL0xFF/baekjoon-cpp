#include <cstdio>

typedef unsigned long long ull;
typedef unsigned int ui;
ull factorial(ui n)
{
    if (n < 0)
        return 0;
    if (n == 0 || n == 1)
        return 1;
    ull ret = 1;
    for (ui loop = 2; loop <= n; loop++)
        ret = ret * loop;
    return ret;
}

int main(void)
{
    ui n = 0;
    scanf("%u", &n);
    ull fact = factorial(n);
    printf("%llu\n", fact);
    ull count = 0;
    while (fact != 0)
    {
        if (fact % 10 != 0)
            break;
        count++;
        fact = fact / 10;
    }
    printf("%llu\n", count);
    return 0;
}