#include <iostream>
#include <map>
#include <string>

int main(void)
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::map<std::string, std::string> data;
    unsigned int n = 0, m = 0;

    std::cin >> n >> m;
    for (unsigned loop = 0; loop < n; loop++)
    {
        std::string site, password;
        std::cin >> site >> password;
        data.insert(std::make_pair(site, password));
    }
    for (unsigned loop = 0; loop < m; loop++)
    {
        std::string site;
        std::cin >> site;
        std::cout << data.find(site)->second << "\n";
    }
    return 0;
}