#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

void organicFarming()
{
    typedef std::pair<int, int> P;
    int n = 0, m = 0, k = 0;
    scanf("%d %d %d", &m, &n, &k);
    int earth[n][m] = {};
    for (int plant = 0, x = 0, y = 0; plant < k; plant++)
    {
        scanf("%d %d", &x, &y);
        earth[y][x]++;
    }
    // BFS
    std::vector<P> visited;
    std::queue<P> queued;
    int count = 0;
    for (int dy = 0; dy < n; dy++)
        for (int dx = 0; dx < m; dx++)
        {
            if (earth[dy][dx] != 1)
                continue;
            if (std::find(visited.begin(), visited.end(), P(dy, dx)) != visited.end())
                continue;
            queued.push({dy, dx});
            while (!queued.empty())
            {
                P p = queued.front();
                queued.pop();
                if (std::find(visited.begin(), visited.end(), p) == visited.end())
                {
                    visited.push_back(p);
                    if (1 <= p.first)
                        if (earth[p.first - 1][p.second] == 1)
                            queued.push({p.first - 1, p.second});
                    if (p.first < n - 1)
                        if (earth[p.first + 1][p.second] == 1)
                            queued.push({p.first + 1, p.second});
                    if (1 <= p.second)
                        if (earth[p.first][p.second - 1] == 1)
                            queued.push({p.first, p.second - 1});
                    if (p.second < m - 1)
                        if (earth[p.first][p.second + 1] == 1)
                            queued.push({p.first, p.second + 1});
                }
            }
            count++;
        }
    printf("%d\n", count);
    return;
}

int main(void)
{
    int t = 0;
    scanf("%d", &t);
    for (int loop = 0; loop < t; loop++)
        organicFarming();
    return 0;
}