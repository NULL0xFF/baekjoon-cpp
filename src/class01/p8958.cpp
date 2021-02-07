#include <cstdio>

int main(void)
{
    int testcaseNum = 0;
    int sequentialNum = 0;
    int score = 0;

    char tempChar[80] = "";

    scanf("%d\n", &testcaseNum);

    for (int loop = 0; loop < testcaseNum; loop++)
    {
        score = 0;
        sequentialNum = 0;
        scanf("%s", tempChar);
        for (int inputLoop = 0; inputLoop < 79; inputLoop++)
        {
            if (tempChar[inputLoop] == '\n' || tempChar[inputLoop] == '\0')
                break;
            else if (tempChar[inputLoop] == 'O')
            {
                sequentialNum++;
                score = score + sequentialNum;
            }
            else if (tempChar[inputLoop] == 'X')
                sequentialNum = 0;
            else
                return -1;
        }
        printf("%d\n", score);
    }
    return 0;
}