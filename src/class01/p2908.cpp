#include <cstdio>

void printReverse(char *string, int size)
{
    for (int index = size - 2; index >= 0; index--)
        printf("%c", string[index]);
}

int main(void)
{
    char a[4], b[4];
    scanf("%s", a);
    scanf("%s", b);

    if (a[2] > b[2])
        printReverse(a, 4);
    else if (a[2] < b[2])
        printReverse(b, 4);
    else
    {
        if (a[1] > b[1])
            printReverse(a, 4);
        else if (a[1] < b[1])
            printReverse(b, 4);
        else
        {
            if (a[0] > b[0])
                printReverse(a, 4);
            else if (a[0] < b[0])
                printReverse(b, 4);
            else
                return -1;
        }
    }
    return 0;
}