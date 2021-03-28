#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

class Point
{
public:
    int x, y;
    Point(int xi = -1, int yi = -1) : x(xi), y(yi) {}
};

class Path
{
public:
    Point p;
    int cost;
    Path(Point pi = Point(-1, -1), int c = -1) : p(pi), cost(c) {}
    static bool compare(Path a, Path b) { return a.p.y == b.p.y ? a.p.x < b.p.x : a.p.y < b.p.y; }
};

Path nextFish(int **data, int width, int height, Point curPos, int value)
{
    bool **visited = new bool *[height]();
    for (int i = 0; i < height; i++)
        visited[i] = new bool[width]();
    std::queue<Path> queued;
    std::vector<Path> fishes;
    queued.push(Path(curPos, 0));
    int minCost = -1;
    while (!queued.empty())
    {
        Path p = queued.front();
        queued.pop();
        if (visited[p.p.y][p.p.x])
            continue;
        visited[p.p.y][p.p.x] = true;
        if (data[p.p.y][p.p.x] != 9 && data[p.p.y][p.p.x] != 0)
            if (data[p.p.y][p.p.x] > value)
                continue;
            else if (data[p.p.y][p.p.x] < value)
            {
                if (minCost == -1)
                    minCost = p.cost;
                if (p.cost == minCost)
                    fishes.push_back(p);
                continue;
            }
        int x = p.p.x, y = p.p.y - 1;
        if (y >= 0)
            if (!visited[y][x])
                queued.push(Path(Point(x, y), p.cost + 1));
        x = p.p.x - 1, y = p.p.y;
        if (x >= 0)
            if (!visited[y][x])
                queued.push(Path(Point(x, y), p.cost + 1));
        x = p.p.x + 1;
        if (x < width)
            if (!visited[y][x])
                queued.push(Path(Point(x, y), p.cost + 1));
        x = p.p.x, y = p.p.y + 1;
        if (y < height)
            if (!visited[y][x])
                queued.push(Path(Point(x, y), p.cost + 1));
    }
    if (fishes.empty())
        return Path(Point(-1, -1), -1);
    else
    {
        std::sort(fishes.begin(), fishes.end(), Path::compare);
        return fishes[0];
    }
}

int main(void)
{
    int **data = nullptr;
    int n = 0;
    Point s;
    scanf("%d", &n);
    data = new int *[n]();
    for (int y = 0; y < n; y++)
    {
        data[y] = new int[n]();
        for (int x = 0; x < n; x++)
        {
            scanf("%d", &data[y][x]);
            if (data[y][x] == 9)
                s = Point(x, y);
        }
    }
    /* BFS */
    int count = 0;
    int time = 0;
    int size = 2;
    Path p;
    while ((p = nextFish(data, n, n, s, size)), p.p.x != -1 && p.p.y != -1)
    {
        data[s.y][s.x] = 0;
        data[p.p.y][p.p.x] = 9;
        s = p.p;
        count++;
        if (count == size)
        {
            size++;
            count = 0;
        }
        time += p.cost;
    }
    /* End of BFS */
    printf("%d\n", time);
    return 0;
}