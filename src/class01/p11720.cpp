#include <cstdio>

int main(void)
{
    int n = 0, sum = 0;
    char *string = nullptr;
    scanf("%d", &n);
    string = new char[n + 1]();
    for (int loop = 0; loop < n; loop++)
        scanf(" %c", &string[loop]);
    for (int loop = 0; loop < n; loop++)
        if (string[loop] == '\0')
            break;
        else
            sum = sum + string[loop] - '0';
    printf("%d", sum);
    return 0;
}