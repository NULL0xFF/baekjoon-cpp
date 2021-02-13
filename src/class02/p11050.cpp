#include <cstdio>

int factorial(const int n){
    int sum = 1;
    for(int i = 2; i <= n; i++)
        sum = sum * i;
    return sum;
}
int nPr(const int n, const int r)
{
    return factorial(n) / factorial(n - r);
}
int nCr(const int n, const int r)
{
    return nPr(n, r) / factorial(r);
}
int main(void)
{
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);
    printf("%d", nCr(n, k));
    return 0;
}