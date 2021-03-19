#include <cstdio>
#include <utility>

typedef std::pair<int, int> p;

int fibonacci(int c[], p o[], int n)
{
    if (c[n] != -1)
        return c[n];
    if (n == 0)
    {
        c[n] = 0;
        o[n] = {1, 0};
        return 0;
    }
    else if (n == 1)
    {
        c[n] = 1;
        o[n] = {0, 1};
        return 1;
    }
    else
    {
        int result = fibonacci(c, o, n - 1) + fibonacci(c, o, n - 2);
        c[n] = result;
        o[n] = {o[n - 1].first + o[n - 2].first, o[n - 1].second + o[n - 2].second};
        return result;
    }
}

int main(void)
{
    int t = 0, n = 0;
    scanf("%d", &t);
    for (int loop = 0; loop < t; loop++)
    {
        scanf("%d", &n);
        int *cache = new int[n + 1]();
        p *output = new std::pair<int, int>[n + 1]();
        for (int loop = 0; loop <= n; loop++)
        {
            cache[loop] = -1;
            output[loop] = {0, 0};
        }
        fibonacci(cache, output, n);
        printf("%d %d\n", output[n].first, output[n].second);
        delete (cache);
        delete (output);
    }
    return 0;
}