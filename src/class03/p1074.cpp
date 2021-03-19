#include <cstdio>
#include <cmath>

int main(void)
{
    int n = 0, r = 0, c = 0, result = 0;
    scanf("%d %d %d", &n, &r, &c);
    int x = pow(2, n) / 2;
    int y = x;
    while (n-- > 0)
    {
        int t = pow(2, n) / 2;
        int s = pow(4, n);
        if (r < y && c < x) // Sector 1
        {
            x = x - t;
            y = y - t;
        }
        else if (r < y && x <= c) // Sector 2
        {
            x = x + t;
            y = y - t;
            result = result + s;
        }
        else if (y <= r && c < x) // Sector 3
        {
            x = x - t;
            y = y + t;
            result = result + (s * 2);
        }
        else // Sector 4
        {
            x = x + t;
            y = y + t;
            result = result + (s * 3);
        }
    }
    printf("%d\n", result);
    return 0;
}