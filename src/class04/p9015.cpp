#include <cstdio>
#include <cmath>

class Point
{
public:
    int x = 0, y = 0;
    Point() {}
};

void largestSquare(void)
{
    Point *array = nullptr;
    int n = 0;
    scanf("%d", &n);
    array = new Point[n]();
    for (int loop = 0; loop < n; loop++)
        scanf("%d %d", &array[loop].x, &array[loop].y);
    int maxSize = 0;
    for (int l1 = 0; l1 < n - 1; l1++)
    {
        for (int l2 = l1 + 1; l2 < n; l2++)
        {
            Point p1 = array[l1], p2 = array[l2], p3, p4;
            int x = p1.x - p2.x;
            int y = p1.y - p2.y;
            p3.x = (x / 2) + y;
            p3.y = (y / 2) - x;
            p4.x = (x / 2) - y;
            p4.y = (y / 2) + x;
            bool p3F = false, p4F = false;
            for (int loop = 0; loop < n; loop++)
                if (array[loop].x == p3.x && array[loop].y == p3.y)
                    p3F = true;
                else if (array[loop].x == p4.x && array[loop].y == p4.y)
                    p4F = true;
            if (p3F && p4F == true)
            {
                int area = pow((p2.y - p1.y), 2) + pow((p2.x - p1.x), 2);
                if (maxSize < area)
                    maxSize = area;
            }
        }
    }
    return;
}

int main(void)
{
    int t = 0;
    scanf("%d", &t);
    for (int tLoop = 0; tLoop < t; tLoop++)
        largestSquare();
    return 0;
}