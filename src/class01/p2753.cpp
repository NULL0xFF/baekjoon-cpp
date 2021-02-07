#include <cstdio>

int main(void)
{
    unsigned short inputNum;
    scanf("%hu", &inputNum);
    if (((inputNum % 4 == 0) && (inputNum % 100 != 0)) || (inputNum % 400 == 0))
        printf("%d", 1);
    else
        printf("%d", 0);
    return 0;
}