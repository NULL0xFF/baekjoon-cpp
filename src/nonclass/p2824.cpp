#include <cstdio>

typedef unsigned long long ull;

// Greatest Common Divisor
ull gcd(ull a, ull b)
{
    if (a < b)
        return gcd(b, a);
    else if (a == b)
        return a;
    ull c = 0;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(void)
{
    ull *A = nullptr, *B = nullptr;
    unsigned int n = 0, m = 0;
    scanf("%u", &n);
    A = new ull[n]();
    for (unsigned int index = 0; index < n; index++)
        scanf("%llu", &A[index]);
    scanf("%u", &m);
    B = new ull[m]();

    ull r = 1;
    bool isBig = false;
    for (unsigned int index = 0; index < m; index++)
        scanf("%llu", &B[index]);
    for (unsigned int i = 0; i < n; i++)
        for (unsigned int j = 0; j < m; j++)
        {
            ull t = gcd(A[i], B[j]);
            r *= t;
            if (r >= 1000000000)
            {
                isBig = true;
                r %= 1000000000;
            }
            A[i] /= t;
            B[j] /= t;
        }
    if (isBig)
        printf("%09llu\n", r);
    else
        printf("%llu\n", r);
    return 0;
}
