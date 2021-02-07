#include <cstdio>

int main(void)
{
    int t, a, b;
    scanf("%d", &t);
    for (int loop = 0; loop < t; loop++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
    }
    return 0;
}