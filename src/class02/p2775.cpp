#include <cstdio>

int members(int floor, int house)
{
    int result = 0;
    if (floor == 0)
        result = house;
    else
        for (int index = 1; index <= house; index++)
            result = result + members(floor - 1, index);
    return result;
}
int main(void)
{
    int t = 0;
    scanf("%d", &t);
    int k = 0, n = 0;
    for (int loop = 0; loop < t; loop++)
    {
        scanf("%d", &k);
        scanf("%d", &n);
        printf("%d\n", members(k, n));
    }
    return 0;
}