#include <cstdio>

int main(void)
{
    // Variables
    char string[101] = "";
    char newString[201] = "";
    int offset = 0, newOffset = 0;
    bool isCPP = false, isJava = false, capitalize = false, underScore = false;

    // Input
    scanf("%s", string);

    // First Character Check
    if ((string[0] >= 'A' && string[0] <= 'Z') || string[0] == '_')
    {
        printf("Error!\n");
        return 0;
    }
    newString[newOffset++] = string[offset++];

    // Loop Check
    while (string[offset] != '\0')
    {
        if (string[offset] >= 'A' && string[offset] <= 'Z')
        {
            if (isCPP)
            {
                printf("Error!\n");
                return 0;
            }
            else if (isJava == false)
                isJava = true;
            capitalize = true;
        }
        else if (string[offset] == '_')
        {
            if (isJava)
            {
                printf("Error!\n");
                return 0;
            }
            else if (isCPP == false)
                isCPP = true;
            if (underScore)
            {
                printf("Error!\n");
                return 0;
            }
            else
                underScore = true;
            offset++;
            continue;
        }
        if (capitalize)
        {
            newString[newOffset++] = '_';
            newString[newOffset++] = string[offset] + ('a' - 'A');
            capitalize = false;
        }
        else if (underScore)
        {
            newString[newOffset++] = string[offset] - ('a' - 'A');
            underScore = false;
        }
        else
            newString[newOffset++] = string[offset];
        offset++;
    }
    if (string[offset - 1] == '_')
        printf("Error!\n");
    else
        printf("%s\n", newString);
    return 0;
}