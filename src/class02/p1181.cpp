#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool compare(std::string a, std ::string b)
{
    return a.size() == b.size() ? a < b : a.size() < b.size();
}

int main(void)
{
    // Disable IO Stream Sync
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    // Main Code
    int n = 0;
    std::cin >> n;

    std::vector<std::string> list(n);

    for (int loop = 0; loop < n; loop++)
    {
        std::cin >> list[loop];
    }

    std::sort(list.begin(), list.end(), compare);

    for (int loop = 0; loop < n; loop++)
    {
        if (loop != 0)
            if (list[loop].compare(list[loop - 1]) == 0)
                continue;
        std::cout << list[loop] << "\n";
    }

    return 0;
}