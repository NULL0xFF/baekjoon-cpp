#include <cstdio>

int main(void)
{
    unsigned int *coins = nullptr,
                 n = 0,
                 k = 0,
                 index = 0, count = 0;
    scanf("%u %u", &n, &k);
    coins = new unsigned int[n]();
    for (index = 0; index < n; index++)
        scanf("%u", &coins[index]);
    while (k != 0)
    {
        if (k / coins[index] > 0)
        {
            count += (k / coins[index]);
            k %= coins[index];
        }
        else
            index--;
    }
    printf("%u\n", count);
    return 0;
}