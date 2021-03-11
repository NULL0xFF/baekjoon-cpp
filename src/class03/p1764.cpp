#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main(void)
{
    std::vector<std::string> listen, observe, searched;
    std::string s;
    int n = 0, m = 0;

    std::cin >> n >> m;

    for (int loop = 0; loop < n; loop++)
    {
        std::cin >> s;
        listen.push_back(s);
    }
    for (int loop = 0; loop < m; loop++)
    {
        std::cin >> s;
        observe.push_back(s);
    }
    std::sort(listen.begin(), listen.end());
    std::sort(observe.begin(), observe.end());
    for (std::string cmp : listen)
        if (std::find(observe.begin(), observe.end(), cmp) != observe.end())
            searched.push_back(cmp);
    std::cout << searched.size() << "\n";
    for (std::string element : searched)
        std::cout << element << "\n";
    return 0;
}