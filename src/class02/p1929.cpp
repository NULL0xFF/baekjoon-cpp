#include <cstdio>

bool *Eratos(int n)
{
    if (n <= 1)
        return nullptr;
    bool *PrimeArray = new bool[n + 1];
    for (int i = 2; i <= n; i++)
        PrimeArray[i] = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (PrimeArray[i])
            for (int j = i * i; j <= n; j += i)
                PrimeArray[j] = false;
    }
    return PrimeArray;
}
void PrimeSelection(int n, int m)
{
    bool *PrimeArray = Eratos(m);
    if (PrimeArray == nullptr)
        return;
    for (int index = n; index <= m; index++)
        if (PrimeArray[index])
            printf("%d\n", index);
    return;
}

int main(void)
{
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    PrimeSelection(n, m);
    return 0;
}