#include <cstdio>
#include <queue>
#include <vector>

typedef std::pair<int, int> point;
typedef std::pair<point, int> container;

int main(void)
{
    bool **map = nullptr;
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
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
    std::queue<container> queued;
    queued.push(std::make_pair(std::make_pair(0, 0), 1));
    while (!queued.empty())
    {
        container c = queued.front();
        point p = c.first;
        queued.pop();
        if (visited[p.first][p.second])
            continue;
        visited[p.first][p.second] = true;
        if (p.first == (n - 1) && p.second == (m - 1))
        {
            printf("%d\n", c.second);
            break;
        }
        /* Adjacent Insertion */
        int num = 0;
        if ((num = p.first - 1) >= 0)
            if (map[num][p.second] && !visited[num][p.second])
                queued.push(std::make_pair(std::make_pair(num, p.second), c.second + 1));
        if ((num = p.first + 1) < n)
            if (map[num][p.second] && !visited[num][p.second])
                queued.push(std::make_pair(std::make_pair(num, p.second), c.second + 1));
        if ((num = p.second - 1) >= 0)
            if (map[p.first][num] && !visited[p.first][num])
                queued.push(std::make_pair(std::make_pair(p.first, num), c.second + 1));
        if ((num = p.second + 1) < m)
            if (map[p.first][num] && !visited[p.first][num])
                queued.push(std::make_pair(std::make_pair(p.first, num), c.second + 1));
        /* End of Adjacent Insertion */
    }
    /* End of BFS */
    return 0;
}