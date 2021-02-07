#include <cstdio>

int main(void)
{
    int *alphabetArray = new int[26]();
    for (int loop = 0; loop < 26; loop++)
        alphabetArray[loop] = -1;
    char *string = new char[101]();
    scanf("%s", string);
    for (int loop = 0; loop < 100; loop++)
        if (string[loop] == '\0')
            break;
        else if (alphabetArray[string[loop] - 'a'] == -1)
            alphabetArray[string[loop] - 'a'] = loop;
    for (int loop = 0; loop < 26; loop++)
        printf("%d ", alphabetArray[loop]);
    return 0;
}