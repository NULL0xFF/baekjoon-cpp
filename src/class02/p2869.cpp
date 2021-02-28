#include <cstdio>
#include <cmath>

int main(void)
{
    unsigned long long a = 0, b = 0, v = 0;
    scanf("%llu %llu %llu", &a, &b, &v);
    printf("%.0lf\n", ceil((double)(v - a) / (double)(a - b) + 1));
    return 0;
}