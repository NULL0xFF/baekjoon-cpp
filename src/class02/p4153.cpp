#include <cstdio>

bool rectangle(int a, int b, int c)
{
    if (b > a && b > c)
        return rectangle(b, a, c);
    if (c > a && c > b)
        return rectangle(c, a, b);
    return ((a * a) == ((b * b) + (c * c)));
}

int main(void)
{
    int a = 0, b = 0, c = 0;
    while (true)
    {
        scanf("%d %d %d", &a, &b, &c);
        if ((a | b | c) == 0)
            break;
        printf("%s\n", (rectangle(a, b, c) ? "right" : "wrong"));
    }
    return 0;
}