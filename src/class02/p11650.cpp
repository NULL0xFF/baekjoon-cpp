#include <cstdio>
#include <algorithm>

class Point
{
public:
    int x, y;
    Point() : Point(0, 0) {}
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
};

bool compare(const Point &a, const Point &b)
{
    if (a.x < b.x)
        return true;
    else if (a.x == b.x && a.y < b.y)
        return true;
    return false;
}

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    Point coordinate[n];
    for (int index = 0; index < n; index++)
        scanf("%d %d", &coordinate[index].x, &coordinate[index].y);
    std::sort(coordinate, coordinate + n, compare);
    for (int index = 0; index < n; index++)
        printf("%d %d\n", coordinate[index].x, coordinate[index].y);
    return 0;
}