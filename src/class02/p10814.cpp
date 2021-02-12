#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

int main(void)
{
    // Disable IO Stream Sync
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n = 0;
    std::map<int, std::vector<std::string> *> dict;

    std::cin >> n;

    {
        int age;
        std::string name;
        for (int loop = 0; loop < n; loop++)
        {
            std::cin >> age;
            std::cin >> name;
            if (dict.find(age) == dict.end())
            {
                std::vector<std::string> *list = new std::vector<std::string>();
                list->push_back(name);
                dict.insert(std::make_pair(age, list));
            }
            else
                dict.find(age)->second->push_back(name);
            // dict.push_back(std::make_pair(age, name));
        }
    }

    for (auto e1 : dict)
        for (auto e2 : *e1.second)
            std::cout << e1.first << " " << e2 << "\n";

    return 0;
}