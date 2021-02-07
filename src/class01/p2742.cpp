#include <cstdio>

int main(void)
{
    unsigned int inputNum;
    scanf("%ud", &inputNum);
    for (unsigned int loop = inputNum; loop > 0; loop--)
        printf("%u\n", loop);
    return 0;
}