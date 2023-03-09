#include <cstdio>
#include <queue>

struct Point
{
    int m, n, h, t;
};

int main(void)
{
    std::queue<Point> ripeTomatoes;
    int width = 0, length = 0, height = 0;
    int ***tomatoes = nullptr;

    // Input
    scanf("%d %d %d", &width, &length, &height);
    tomatoes = new int **[height]();
    for (int h = 0; h < height; h++)
    {
        tomatoes[h] = new int *[length]();
        for (int l = 0; l < length; l++)
        {
            tomatoes[h][l] = new int[width]();
            for (int w = 0; w < width; w++)
            {
                int status = 0;
                scanf("%d", &status);
                tomatoes[h][l][w] = status;

                // Remember Riped Tomatoes
                if (status == 1)
                {
                    ripeTomatoes.push(Point{w, l, h, 0});
                }
            }
        }
    }

    // BFS
    int maxTime = 0;
    while (!ripeTomatoes.empty())
    {
        Point p = ripeTomatoes.front();
        ripeTomatoes.pop();

        // Update Time
        maxTime = p.t > maxTime ? p.t : maxTime;

        // Check Up
        if ((p.h + 1) < height)
        {
            if (tomatoes[p.h + 1][p.n][p.m] == 0)
            {
                tomatoes[p.h + 1][p.n][p.m] = 1;
                ripeTomatoes.push(Point{p.m, p.n, p.h + 1, p.t + 1});
            }
        }
        // Check Down
        if ((p.h - 1) >= 0)
        {
            if (tomatoes[p.h - 1][p.n][p.m] == 0)
            {
                tomatoes[p.h - 1][p.n][p.m] = 1;
                ripeTomatoes.push(Point{p.m, p.n, p.h - 1, p.t + 1});
            }
        }
        // Check North
        if ((p.n - 1) >= 0)
        {
            if (tomatoes[p.h][p.n - 1][p.m] == 0)
            {
                tomatoes[p.h][p.n - 1][p.m] = 1;
                ripeTomatoes.push(Point{p.m, p.n - 1, p.h, p.t + 1});
            }
        }
        // Check South
        if ((p.n + 1) < length)
        {
            if (tomatoes[p.h][p.n + 1][p.m] == 0)
            {
                tomatoes[p.h][p.n + 1][p.m] = 1;
                ripeTomatoes.push(Point{p.m, p.n + 1, p.h, p.t + 1});
            }
        }
        // Check East
        if ((p.m + 1) < width)
        {
            if (tomatoes[p.h][p.n][p.m + 1] == 0)
            {
                tomatoes[p.h][p.n][p.m + 1] = 1;
                ripeTomatoes.push(Point{p.m + 1, p.n, p.h, p.t + 1});
            }
        }
        // Check West
        if ((p.m - 1) >= 0)
        {
            if (tomatoes[p.h][p.n][p.m - 1] == 0)
            {
                tomatoes[p.h][p.n][p.m - 1] = 1;
                ripeTomatoes.push(Point{p.m - 1, p.n, p.h, p.t + 1});
            }
        }
    }

    // Check Raw Tomatoes
    for (int h = 0; h < height; h++)
    {
        for (int l = 0; l < length; l++)
        {
            for (int w = 0; w < width; w++)
            {
                if (tomatoes[h][l][w] == 0)
                {
                    printf("-1\n");
                    return 0;
                }
            }
        }
    }

    printf("%d\n", maxTime);
    return 0;
}