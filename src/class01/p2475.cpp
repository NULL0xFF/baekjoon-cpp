#include <cstdio>
#include <cmath>

int main(void)
{
    int inputNum = 0, parity = 0;
    for (int serialIndex = 0; serialIndex < 5; serialIndex++)
    {
        scanf("%d", &inputNum);
        parity = parity + std::pow(inputNum, 2);
    }
    parity = parity % 10;
    printf("%d", parity);
}