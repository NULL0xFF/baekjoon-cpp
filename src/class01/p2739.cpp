#include <cstdio>

void gugudan(int n)
{
    for (int i = 1; i < 10; i++)
        printf("%d * %d = %d\n", n, i, (n * i));
}

int main(void)
{
    int inputNum;
    scanf("%d", &inputNum);
    gugudan(inputNum);
    return 0;
}