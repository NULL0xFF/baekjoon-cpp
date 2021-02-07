#include <cstdio>

int main(void)
{
    int n = 0, x = 0;
    scanf("%d %d", &n, &x);
    int *arr = new int[n]();
    for (int loop = 0; loop < n; loop++)
        scanf("%d", &arr[loop]);
    for (int loop = 0; loop < n; loop++)
        if (arr[loop] < x)
            printf("%d ", arr[loop]);
    return 0;
}