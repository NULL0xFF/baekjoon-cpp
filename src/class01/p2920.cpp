#include <cstdio>

int main(void)
{
    bool ascend = false;
    bool descend = false;
    int prev = -1, inputNum = 0;
    for (int loop = 0; loop < 8; loop++)
    {
        scanf("%d", &inputNum);
        if (prev == -1)
        {
            prev = inputNum;
            continue;
        }
        else if (prev < inputNum)
            ascend = true;
        else if (prev > inputNum)
            descend = true;
        prev = inputNum;
    }
    if (ascend && descend == true)
        printf("mixed");
    else if (ascend)
        printf("ascending");
    else if (descend)
        printf("descending");
    else
        return -1;
    return 0;
}