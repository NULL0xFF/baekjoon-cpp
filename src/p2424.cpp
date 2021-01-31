#include <cstdio>

long long int gcd(long long a, long long b)
{
    if (b)
        return gcd(b, a % b);
    else
        return a;
}

int main(int argc, char *argv[])
{
    int input = 0;
    long long int n = (long long)1, m = (long long)1;

    // Input N
    scanf("%d", &input);
    for (int loop = input; loop > 0; loop--)
    {
        scanf("%d", &input);
        n = n * (long long)input;
        printf("%d, %lld\n", loop, n);
    }

    // Input M
    scanf("%d", &input);
    for (int loop = input; loop > 0; loop--)
    {
        scanf("%d", &input);
        m = m * (long long)input;
    }

    // GCD Output
    printf("%lld, %lld, %lld\n", n, m, gcd(n, m));

    return 0;
}