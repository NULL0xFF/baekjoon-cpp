#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

typedef std::pair<int, int> point;

int main(void)
{
    bool **map = nullptr;
    int n = 0, m = 0;
    scanf("%d", &n);
    m = n;
    map = new bool *[n]();
    for (int y = 0; y < n; y++)
    {
        map[y] = new bool[m]();
        for (int x = 0; x < m; x++)
        {
            char c = '\0';
            scanf("%c", &c);
            if (c == '\n')
            {
                x--;
                continue;
            }
            map[y][x] = c - '0';
        }
    }
    /* BFS */
    bool **visited = new bool *[n]();
    for (int y = 0; y < n; y++)
        visited[y] = new bool[m]();
    std::queue<point> queued;
    std::vector<int> village;
    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
        {
            if (!map[y][x] || visited[y][x])
                continue;
            queued.push(std::make_pair(y, x));
            int count = 0;
            while (!queued.empty())
            {
                point p = queued.front();
                queued.pop();
                if (visited[p.first][p.second])
                    continue;
                visited[p.first][p.second] = true;
                count++;
                /* Adjacent Insertion */
                int num = 0;
                if ((num = p.first - 1) >= 0)
                    if (map[num][p.second] && !visited[num][p.second])
                        queued.push(std::make_pair(num, p.second));
                if ((num = p.first + 1) < n)
                    if (map[num][p.second] && !visited[num][p.second])
                        queued.push(std::make_pair(num, p.second));
                if ((num = p.second - 1) >= 0)
                    if (map[p.first][num] && !visited[p.first][num])
                        queued.push(std::make_pair(p.first, num));
                if ((num = p.second + 1) < m)
                    if (map[p.first][num] && !visited[p.first][num])
                        queued.push(std::make_pair(p.first, num));
                /* End of Adjacent Insertion */
            }
            village.push_back(count);
        }
    /* End of BFS */
    std::sort(village.begin(), village.end());
    printf("%ld\n", village.size());
    for (int e : village)
        printf("%d\n", e);
    return 0;
}