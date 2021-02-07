#include <cstdio>

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    for (int loop = 1; loop <= n; loop++)
    {
        printf("%*s", n - loop, "");
        for (int stars = 1; stars <= loop; stars++)
            printf("*");
        printf("\n");
    }
    return 0;
}