#include <cstdio>

int main(void)
{
    char input[1000001];
    fgets(input, 1000000, stdin);

    int count[26];
    char tempChar = '\0';
    for (unsigned int loop = 0; input[loop] != '\0'; loop++)
    {
        tempChar = input[loop];
        if (tempChar >= 'a' && tempChar <= 'z')

            count[tempChar - 'a']++;
        else if (tempChar >= 'A' && tempChar <= 'Z')
            count[tempChar - 'A']++;
    }

    int offset = 0;
    bool duplicated = false;
    for (unsigned int loop = 1; loop < 26; loop++)
    {
        if (count[offset] < count[loop])
        {
            offset = loop;
            duplicated = false;
        }
        else if (count[offset] == count[loop])
            duplicated = true;
    }

    printf("%c", (duplicated ? '?' : (char)(offset + (int) 'A')));

    return 0;
}