#include <cstdio>
#include <vector>
#include <set>

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    std::vector<long long> A;
    {
        long long input = 0L;
        for (int loop = 0; loop < n; loop++)
        {
            scanf("%lld", &input);
            A.push_back(input);
        }
    }
    std::set<long long> R[n];
    {
        long long point = 0L;
        for (int l1 = 0; l1 < n; l1++)
        {
            point = A.at(l1);
            R[l1].insert(point);
            for (auto it : A)
            {
                if (it > point)
                {
                    R[l1].insert(it);
                    point = it;
                }
            }
        }
    }
    int size = 0;
    int ptr = 0;
    for (int loop = 0; loop < n; loop++)
    {
        if (R[loop].size() >= size)
        {
            size = R[loop].size();
            ptr = loop;
        }
    }
    printf("%d\n", size);
    for (auto it : R[ptr])
        printf("%lld ", it);
    return 0;
}