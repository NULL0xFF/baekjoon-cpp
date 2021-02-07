#include <cstdio>

int main(void)
{
    int inputNum = 0, maxNum = 0, indexNum = 0;
    for (int loop = 1; loop <= 9; loop++)
    {
        scanf("%d", &inputNum);
        if (maxNum < inputNum)
        {
            maxNum = inputNum;
            indexNum = loop;
        }
    }
    printf("%d\n%d", maxNum, indexNum);
    return 0;
}