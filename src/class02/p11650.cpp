#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

int main(void)
{
    std::map<int, std::vector<int> *> coordinationMap;
    int n = 0;
    scanf("%d", &n);
    {
        int a = 0, b = 0;
        std::vector<int> *ptr = nullptr;
        for (int loop = 0; loop < n; loop++)
        {
            scanf("%d %d", &a, &b);
            if (coordinationMap.find(a) == coordinationMap.end())
            {
                ptr = new std::vector<int>();
                ptr->push_back(b);
                coordinationMap.insert(std::make_pair(a, ptr));
                ptr = nullptr;
            }
            else
                coordinationMap.find(a)->second->push_back(b);
        }
    }
    for (auto element : coordinationMap)
        std::sort(element.second->begin(), element.second->end(), std::less<int>());

    for (auto element : coordinationMap)
        for(auto point : *element.second)
            printf("%d %d\n", element.first, point);
    return 0;
}