#include <cstdio>

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    int loop = 0;
    while (true)
    {
        if (loop > n)
        {
            printf("0\n");
            break;
        }
        int sum = loop, k = loop;
        while (k != 0)
        {
            sum = sum + (k % 10);
            k = k / 10;
        }
        if (sum == n)
        {
            printf("%d\n", loop);
            break;
        }
        loop++;
    }
    return 0;
}