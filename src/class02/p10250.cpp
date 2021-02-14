#include <cstdio>

int main(void)
{
    int t = 0, h = 0, w = 0, n = 0;
    int *hotel = nullptr;
    scanf("%d", &t);
    for (int loop = 0; loop < t; loop++)
    {
        scanf("%d %d %d", &h, &w, &n);
        hotel = new int[h * w]();
        for(int dw = 0, index = 0; dw < w; dw++)
            for(int dh = 0; dh < h; dh++)
            {
                hotel[index] = ((dh + 1) * 100) + (dw + 1);
                index++;
            }
        printf("%d\n", hotel[n - 1]);
    }
    return 0;
}