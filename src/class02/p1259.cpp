#include <iostream>
#include <string>

bool palindrome(std::string str)
{
    for (int i = 0; i < str.length() / 2; i++)
        if (str[i] != str[str.length() - (i + 1)])
            return false;
    return true;
}

int main(void)
{
    // Disable IO Stream Sync
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    // Main Code
    std::string str;
    while (true)
    {
        std::cin >> str;
        if (str.compare("0") == 0)
            break;
        std::cout << (palindrome(str) == true ? "yes" : "no") << "\n";
    }
    return 0;
}