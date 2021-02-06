#include <iostream>
#include <string>
#include <cstdio>

int main(void)
{
    std::string inputString;
    std::getline(std::cin, inputString);

    int count = 0;
    bool prev = false, space = false;
    for (auto it = inputString.begin(); *it != '\0'; it++)
    {
        if (*it != ' '){
            space = false;
            prev = true;
        }
        else if (prev == true)
        {
            prev = false;
            space = true;
            count++;
        }
    }
    if(prev == true)
        count++;
    printf("%d", count);
    return 0;
}