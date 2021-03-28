#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>

class Pos
{
public:
    int x = 0, y = 0, z = 0;
    Pos(int xi = 0, int yi = 0, int zi = 0) : x(xi), y(yi), z(zi) {}
};

typedef std::pair<int, int> Point;

int main(void)
{
    std::queue<std::pair<Pos, int>> queued;
    std::map<Point, int> *tomatoes = nullptr;
    int breadth = 0, length = 0, height = 0;
    scanf("%d %d %d", &breadth, &length, &height);
    tomatoes = new std::map<Point, int>[height]();
    for (int h = 0; h < height; h++)
        for (int n = 0; n < length; n++)
            for (int m = 0, input = 0; m < breadth; m++)
            {
                scanf("%d", &input);
                tomatoes[h].emplace(std::make_pair(m, n), input);
                if (input == 1)
                    queued.push(std::make_pair(Pos(m, h, n), 0));
            }
    int time = 0;
    while (!queued.empty())
    {
        Pos p = queued.front().first;
        int t = queued.front().second;
        queued.pop();
        if (time < t)
            time = t;
        int h = p.y, m = p.x, n = p.z;
        auto it = tomatoes[h].find(std::make_pair(m, n));
        tomatoes[h].find(std::make_pair(m, n))->second = 1;
        h++;
        it = tomatoes[h].find(std::make_pair(m, n));
        if (h < height)
            if (it->second == 0)
                queued.push(std::make_pair(Pos(m, h, n), t + 1));
        h--, n--;
        it = tomatoes[h].find(std::make_pair(m, n));
        if (n >= 0)
            if (it->second == 0)
                queued.push(std::make_pair(Pos(m, h, n), t + 1));
        n++, m++;
        it = tomatoes[h].find(std::make_pair(m, n));
        if (m < breadth)
            if (it->second == 0)
                queued.push(std::make_pair(Pos(m, h, n), t + 1));
        n++, m--;
        it = tomatoes[h].find(std::make_pair(m, n));
        if (n < length)
            if (it->second == 0)
                queued.push(std::make_pair(Pos(m, h, n), t + 1));
        n--, m--;
        it = tomatoes[h].find(std::make_pair(m, n));
        if (m >= 0)
            if (it->second == 0)
                queued.push(std::make_pair(Pos(m, h, n), t + 1));
        m++, h--;
        it = tomatoes[h].find(std::make_pair(m, n));
        if (h >= 0)
            if (it->second == 0)
                queued.push(std::make_pair(Pos(m, h, n), t + 1));
    }
    for (int h = 0; h < height; h++)
        for (auto it : tomatoes[h])
            if (it.second == 0)
            {
                printf("-1\n");
                return 0;
            }
    printf("%d\n", time);
    return 0;
}