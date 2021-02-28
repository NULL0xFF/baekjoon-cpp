#include <cstdio>

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    int big = -1, small = -1;
    for (big = n / 5; big >= 0; big--)
        if ((n - (big * 5)) % 3 == 0)
        {
            small = (n - (big * 5)) / 3;
            break;
        }
    if (big == -1 || small == -1)
        printf("-1\n");
    else
        printf("%d\n", big + small);
    return 0;
}