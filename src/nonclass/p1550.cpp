#include <cstdio>

int main(int argc, char *argv[])
{
    int i = 0;
    char c[6];

    scanf("%6s", c);

    for (short loop = 0; c[loop] != 0 && loop < 6; loop++)
    {
        i = i * 16;
        if (c[loop] >= 'A' && c[loop] <= 'Z')
            i = i + c[loop] - ('A' - 10);
        else if (c[loop] >= '0' && c[loop] <= '9')
            i = i + c[loop] - '0';
    }
    printf("%d", i);
    return 0;
}