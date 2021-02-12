#include <cstdio>
#include <map>
#include <vector>

int main(void)
{
    int n = 0, m = 0;

    std::map<int, int> nMap;
    std::vector<int> mArr;

    {
        int i = 0;

        scanf("%d", &n);
        for (int loop = 0; loop < n; loop++)
        {
            scanf("%d", &i);
            if(nMap.find(i) == nMap.end())
                nMap.insert(std::make_pair(i, 1));
            else
                nMap.find(i)->second++;
        }

        scanf("%d", &m);
        for (int loop = 0; loop < m; loop++)
        {
            scanf("%d", &i);
            mArr.push_back(i);
        }
    }

    for (int loop = 0; loop < m; loop++)
        printf("%d ", nMap.find(mArr[loop])->second);
    return 0;
}