#include <cstdio>

int min(const int a, const int b) { return a < b ? a : b; }

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    int d[n + 1] = {-1, 0};
    for (int index = 2; index <= n; index++)
    {
        d[index] = d[index - 1] + 1; // Rule 3
        if (index % 3 == 0)
            d[index] = min(d[index], d[index / 3] + 1); // Rule 1
        if (index % 2 == 0)
            d[index] = min(d[index], d[index / 2] + 1); // Rule 2
    }
    printf("%d\n", d[n]);
    return 0;
}