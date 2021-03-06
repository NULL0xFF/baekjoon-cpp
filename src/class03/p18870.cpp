#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    long long xi[n] = {};
    std::vector<long long> v;
    std::map<long long, long long> m;
    for (int index = 0; index < n; index++)
    {
        scanf("%lld", &xi[index]);
        v.push_back(xi[index]);
    }
    std::sort(v.begin(), v.end());
    for (unsigned int loop = 0, index = 0; loop < v.size(); loop++)
        if (m.find(v[loop]) == m.end())
            m.insert(std::make_pair(v[loop], index++));
    for (int index = 0; index < n; index++)
        printf("%lld ", m.find(xi[index])->second);
    return 0;
}