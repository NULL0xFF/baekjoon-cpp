#include <cstdio>
#include <queue>

class Tomato
{
public:
    int x, y, time;
    Tomato(int xi, int yi, int t) : x(xi), y(yi), time(t) {}
};

int main(void)
{
    std::queue<Tomato> queued;
    int **container = nullptr;
    int m = 0, n = 0, time = 0;

    scanf("%d %d", &m, &n);
    container = new int *[n]();
    for (int y = 0; y < n; y++)
    {
        container[y] = new int[m]();
        for (int x = 0; x < m; x++)
        {
            scanf("%d", &container[y][x]);
            if (container[y][x] == 1)
                queued.push(Tomato(x, y, 0));
        }
    }

    /* BFS */
    while (!queued.empty())
    {
        Tomato t = queued.front();
        queued.pop();
        if (time < t.time)
            time = t.time;
        // Up
        int x = t.x, y = t.y - 1;
        if (y >= 0)
            if (container[y][x] == 0)
            {
                container[y][x] = 1;
                queued.push(Tomato(x, y, t.time + 1));
            }
        y = t.y + 1;
        if (y < n)
            if (container[y][x] == 0)
            {
                container[y][x] = 1;
                queued.push(Tomato(x, y, t.time + 1));
            }
        x = t.x - 1, y = t.y;
        if (x >= 0)
            if (container[y][x] == 0)
            {
                container[y][x] = 1;
                queued.push(Tomato(x, y, t.time + 1));
            }
        x = t.x + 1;
        if (x < m)
            if (container[y][x] == 0)
            {
                container[y][x] = 1;
                queued.push(Tomato(x, y, t.time + 1));
            }
    }
    /* End of BFS */

    // Check Unchanged Tomato(s)
    bool isChanged = true;
    for (int y = 0; y < n && isChanged; y++)
        for (int x = 0; x < m && isChanged; x++)
            if (container[y][x] == 0)
                isChanged = false;

    printf("%d\n", isChanged ? time : -1);

    return 0;
}