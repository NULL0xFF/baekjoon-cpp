#include <iostream>
#include <string>

int main(void)
{
    std::string str;
    int n, i = 0, count = 0;

    std::cin >> n;

    while (count != n)
    {
        i++;
        str = std::to_string(i);
        if (str.find("666") != -1)
            count++;
    }

    std::cout << i << "\n";

    return 0;
}