#include <cstdio>

int main(void)
{
    int h = 0, m = 0;
    scanf("%d %d", &h, &m);
    m = m - 45;
    if (m < 0)
    {
        m = m + 60;
        h--;
    }
    if (h < 0)
        h = h + 24;
    else if(h >= 24)
        h = h - 24;
    printf("%d %d", h, m);

    return 0;
}