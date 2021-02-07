#include <cstdio>

int main(void)
{
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    if (x == 0 || x == w || y == 0 || y == h)
        printf("0");
    else
    {
        int min = 1000;
        // Left
        if (x < min)
            min = x;
        // Right
        if (w - x < min)
            min = w - x;
        // Down
        if (y < min)
            min = y;
        // Up
        if (h - y < min)
            min = h - y;
        printf("%d", min);
    }
    return 0;
}
