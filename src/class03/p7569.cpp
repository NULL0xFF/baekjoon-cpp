#include <cstdio>
#include <vector>
#include <queue>

class Point
{
public:
    int x = 0, y = 0, z = 0;
    Point(int xi = 0, int yi = 0, int zi = 0) : x(xi), y(yi), z(zi) {}
};

int main(void)
{
    std::queue<std::pair<Point, int>> queued;
    int ***tomatoes = nullptr;
    int breadth = 0, length = 0, height = 0;
    scanf("%d %d %d", &breadth, &length, &height);
    tomatoes = new int **[height]();
    for (int h = 0; h < height; h++)
    {
        tomatoes[h] = new int *[length]();
        for (int n = 0; n < length; n++)
        {
            tomatoes[h][n] = new int[breadth]();
            for (int m = 0; m < breadth; m++)
            {
                scanf("%d", &tomatoes[h][n][m]);
                if (tomatoes[h][n][m] == 1)
                    queued.push(std::make_pair(Point(m, h, n), 0));
            }
        }
    }
    int time = 0;
    while (!queued.empty())
    {
        Point p = queued.front().first;
        int t = queued.front().second;
        queued.pop();
        if (time < t)
            time = t;
        int h = p.y, m = p.x, n = p.z;
        tomatoes[h][n][m] = 1;
        h++;
        if (h < height)
            if (tomatoes[h][n][m] == 0)
                queued.push(std::make_pair(Point(m, h, n), t + 1));
        h--, n--;
        if (n >= 0)
            if (tomatoes[h][n][m] == 0)
                queued.push(std::make_pair(Point(m, h, n), t + 1));
        n++, m++;
        if (m < breadth)
            if (tomatoes[h][n][m] == 0)
                queued.push(std::make_pair(Point(m, h, n), t + 1));
        n++, m--;
        if (n < length)
            if (tomatoes[h][n][m] == 0)
                queued.push(std::make_pair(Point(m, h, n), t + 1));
        n--, m--;
        if (m >= 0)
            if (tomatoes[h][n][m] == 0)
                queued.push(std::make_pair(Point(m, h, n), t + 1));
        m++, h--;
        if (h >= 0)
            if (tomatoes[h][n][m] == 0)
                queued.push(std::make_pair(Point(m, h, n), t + 1));
    }
    bool isRipen = true;
    for (int h = 0; h < height && isRipen; h++)
        for (int n = 0; n < length && isRipen; n++)
            for (int m = 0; m < breadth && isRipen; m++)
                if (tomatoes[h][n][m] == 0)
                    isRipen = false;
    printf("%d\n", isRipen ? time : -1);

    return 0;
}