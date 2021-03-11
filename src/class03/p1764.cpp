#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main(void)
{
    std::vector<std::string> names, searched;
    std::string s;
    int n = 0, m = 0;

    std::cin >> n >> m;

    for (int loop = 0; loop < n + m; loop++)
    {
        std::cin >> s;
        names.push_back(s);
    }
    std::sort(names.begin(), names.end());
    for (int index = 0; index < n + m; index++)
        if (names[index].compare(names[index + 1]) == 0) // check if names vector has two same values
        {
            searched.push_back(names[index]);
            index++; // skip duplicated entry
        }

    std::cout << searched.size() << "\n";
    for (std::string element : searched)
        std::cout << element << "\n";
    return 0;
}