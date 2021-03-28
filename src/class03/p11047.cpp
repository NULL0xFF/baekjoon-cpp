#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

int main(void)
{
    unsigned int n = 0,
                 k = 0,
                 count = 0;
    std::vector<unsigned int> coins;

    scanf("%u %u", &n, &k);

    for (int index = 0, coin = 0; index < n; index++)
    {
        scanf("%u", &coin);
        coins.push_back(coin);
    }

    std::sort(coins.begin(), coins.end(), std::less_equal<unsigned int>());

    int offset = coins.size() - 1;
    while (k != 0)
    {
        if (k / coins[offset] > 0)
        {
            count += (k / coins[offset]);
            k %= coins[offset];
        }
        else
        {
            if (offset == 0)
                break;
            else
                offset--;
        }
    }
    printf("%u\n", count);
    return 0;
}