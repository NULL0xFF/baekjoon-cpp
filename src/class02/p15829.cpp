#include <cstdio>

// modular operations
// 1. (a + b) mod n = {(a mod n) + (b mod n)} mod n
// 2. (a - b) mod n = {(a mod n) - (b mod n)} mod n
// 3. (a * b) mod n = {(a mod n) * (b mod n)} mod n
int main(void)
{
    const int mod = 1234567891;
    const int mul = 31;

    int l = 0;
    char *input = nullptr;

    scanf("%d", &l);
    input = new char[l + 1];
    scanf(" %s", input);

    long long hash = 0;
    long long r = 1;
    for (int loop = 0; loop < l; loop++)
    {
        hash = (hash + ((input[loop] - 'a') + 1) * r) % mod;
        r = (r * mul) % mod;
    }
    printf("%lld", hash);
    return 0;
}