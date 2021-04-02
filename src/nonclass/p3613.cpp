/*
 * 공통
 *  - 첫 단어는 소문자로 되어있는가
 * Java
 *  - 이후 단어는 대문자로 시작하는가
 * C++
 *  - 이후 단어는 소문자이며, _(밑줄)로 시작하는가
 *  - _(밑줄)이 한 개 인가
 */
#include <cstdio>

int main(void)
{
    char string[101] = "";
    char newString[201] = "";
    scanf("%s", string);
    if (string[0] >= 'A' && string[0] <= 'Z')
        printf("Error!\n");
    newString[0] = string[0];
    int offset = 1;
    int newStringOffset = 1;
    bool isJava = false, isCPP = false, capitalize = false;
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
            capitalize = true;
            offset++;
            continue;
        }
        newString[newStringOffset++] = capitalize ? string[offset] - ('a' - 'A') : string[offset];
        capitalize = false;
        offset++;
    }
    printf("%s\n", newString);
    return 0;
}