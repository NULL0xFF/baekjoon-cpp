#include <iostream>
#include <map>
#include <string>
#include <vector>

int main(void)
{
    int t = 0;
    std::cin >> t;
    for (int test = 0; test < t; test++)
    {
        std::map<std::string, std::vector<std::string>> dict;
        int n = 0;

        std::cin >> n;
        for (int loop = 0; loop < n; loop++)
        {
            std::string name, type;
            std::cin >> name >> type;
            dict[type].push_back(name);
        }
        int ret = 1;
        for (auto it : dict)
        {
            ret *= it.second.size() + 1;
        }
        ret--;
        std::cout << ret << "\n";
    }
    return 0;
}