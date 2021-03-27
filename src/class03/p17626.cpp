#include <cstdio>
#include <cmath>

int main(void)
{
    int n = 0, min = 0;
    scanf("%d", &n);
    for (int offset = 0; offset < n; offset++)
    {
        int count = 0;
        int t = n;
        int i = (int)sqrt(t - offset);
        i *= i;
        t -= i;
        count++;
        while (t != 0)
        {
            int i = (int)sqrt(t);
            i *= i;
            t -= i;
            count++;
        }
        if (min == 0 || count < min)
            min = count;
        offset++;
    }
    printf("%d\n", min);
    return 0;
}