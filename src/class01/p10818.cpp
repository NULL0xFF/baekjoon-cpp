#include <cstdio>

int main(void)
{
    int testcaseNum = 0;
    scanf("%d", &testcaseNum);
    int input = 0;
    scanf("%d", &input);
    int min = input, max = input;
    for (int loop = 1; loop < testcaseNum; loop++)
    {
        scanf("%d", &input);
        if (input < min)
            min = input;
        else if (input > max)
            max = input;
    }
    printf("%d %d", min, max);
    return 0;
}