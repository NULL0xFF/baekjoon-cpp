#include <cstdio>

int main(void)
{
    int numArr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int sumNum = 1;
    for (int loop = 0; loop < 3; loop++)
    {
        scanf("%d", &numArr[0]);
        sumNum = sumNum * numArr[0];
    }
    numArr[0] = 0;
    while (sumNum != 0)
    {
        numArr[sumNum % 10]++;
        sumNum = sumNum / 10;
    }
    for (int loop = 0; loop < 10; loop++)
        printf("%d\n", numArr[loop]);
    return 0;
}