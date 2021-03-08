#include <cstdio>

// c = getchar();
// if (c == '\n')
// {
//     for (int ptr = (4 - index), i = 0; ptr < 4; ptr++, i++)
//         ipv6[(group * 5) + ptr] = input[i];
//     break;
// }
// if (c == ':')
// {
//     if (colon)
//     {
//     }
//     else
//     {
//         for (int ptr = (4 - index), i = 0; ptr < 4; ptr++, i++)
//             ipv6[(group * 5) + ptr] = input[i];
//         index = 0;
//         group++;
//         for (int ptr = 0; ptr < 4; ptr++)
//             input[ptr] = '\0';
//         colon = true;
//     }
// }
// else
// {
//     input[index] = c;
//     index++;
//     if (index > 4)
//     {
//         for (int ptr = 0; ptr < 4; ptr++)
//             ipv6[(group * 5) + ptr] = input[ptr];
//         index = 0;
//         group++;
//     }
// }

int main(void)
{
    char buffer[40] = "";
    char token[8][5] = {"0000", "0000", "0000", "0000", "0000", "0000", "0000", "0000"};
    char input[5] = "";
    bool colon = false, doubleColon = false;
    int loop = 0;
    while (loop < 8)
    {
        for (int index = 0; index < 5; index++)
        {
            char c = getchar();
            if (c == ':' || c == '\n')
            {
                if (c == ':' && colon == true)
                {
                    doubleColon = true;
                }
                else
                {
                    for (int offset = (4 - index), ptr = 0; offset < 4; offset++, ptr++)
                        token[loop][offset] = input[ptr];
                    colon = true;
                }
                break;
            }
            else
            {
                input[index] = c;
                colon = false;
            }
        }
        if (doubleColon == true)
            break;
        loop++;
    }
    int offset = 7;
    if (doubleColon == true)
    {
        char c = '\0';
        for (int index = 0; (c = getchar()) != '\n'; index++)
        {
            if (c == ':')
                offset--;
            buffer[index] = c;
        }
    }
    int bufferIndex = 0;
    loop = offset;
    while (loop < 8)
    {
        for (int index = 0; index < 5; index++)
        {
            char c = buffer[bufferIndex];
            bufferIndex++;
            if (c == ':' || c == '\0')
            {
                for (int offset = (4 - index), ptr = 0; offset < 4; offset++, ptr++)
                    token[loop][offset] = input[ptr];
                break;
            }
            else
                input[index] = c;
        }
        loop++;
    }
    for (int index = 0; index < 8; index++)
        printf("%s%c", token[index], (index != 7) ? ':' : '\n');
    return 0;
}