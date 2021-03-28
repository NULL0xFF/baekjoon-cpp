#include <cstdio>

int climb(int stair[], int n, int pos, int *cache = nullptr)
{
}

int main(void)
{
    int n = 0, *stair = nullptr;
    scanf("%d", &n);
    stair = new int[n]();
    for (int index = 0; index < n; index++)
        scanf("%d", &stair[index]);
    printf("%d\n", climb(stair, n, new int[n + 1]()));
    return 0;
}