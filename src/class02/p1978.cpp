#include <cstdio>
#include <cmath>

// O(n) = root(n - 2)
bool isPrime(const int number)
{
    if (number <= 1)
        return false;
    for (int i = 2; i <= sqrt(number); i++)
        if (number % i == 0)
            return false;
    return true;
}

int main(void)
{
    int n = 0, count = 0;

    scanf("%d", &n);

    {
        int input = 0;
        for (int loop = 0; loop < n; loop++)
        {
            scanf("%d", &input);
            if (isPrime(input))
                count++;
        }
    }

    printf("%d", count);
    return 0;
}