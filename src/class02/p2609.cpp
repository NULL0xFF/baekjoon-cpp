#include <cstdio>

// Greatest Common Divisor
int gcd(int a, int b)
{
    if (a < b)
        return gcd(b, a);
    else if (a == b)
        return a;
    int c = 0;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

// Least Common Multiple
int lcm(const int a, const int b)
{
    return ((a * b) / gcd(a, b));
}

int main(void)
{
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a, b));
    printf("%d\n", lcm(a, b));
    return 0;
}