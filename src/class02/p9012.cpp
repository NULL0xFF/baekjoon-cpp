#include <iostream>
#include <string>
#include <vector>

int main(void)
{
    int n;
    std::cin >> n;
    std::string inputString;
    std::vector<std::string> inputArray;

    for (int i = 0; i < n; i++)
    {
        std::cin >> inputString;
        inputArray.push_back(inputString);
    }

    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        int count = 0;
        for (int index = 0; index < inputArray[i].size() && flag == true; index++)
        {
            if (inputArray[i].at(index) == '(')
                count++;
            else if (inputArray[i].at(index) == ')')
                count--;
            if (count < 0)
                flag = false;
        }
        if (flag == false || count != 0)
            std::cout << "NO";
        else
            std::cout << "YES";
        std::cout << std::endl;
    }

    // Debug
    // for (auto it = inputArray.begin(); it != inputArray.end(); it++)
    //     std::cout << *it << std::endl;

    return 0;
}