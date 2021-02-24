#include <cstdio>

double maximumAreaOfSquare(void);

int main(void)
{
    int testCase = 0;
    scanf("%d", &testCase);
    for (int loop = 0; loop < testCase; loop++)
        printf("%.0lf\n", maximumAreaOfSquare());
    return 0;
}

#include <cmath>
#include <set>
typedef std::pair<int, int> Point;
double maximumAreaOfSquare(void)
{
    int numberOfPoints = 0;
    double maxArea = 0.0F;
    scanf("%d", &numberOfPoints);
    Point pArray[numberOfPoints];
    std::set<Point> pSet;
    for (int loop = 0; loop < numberOfPoints; loop++)
    {
        scanf("%d %d", &pArray[loop].first, &pArray[loop].second);
        pSet.insert(pArray[loop]);
    }
    for (int l1 = 0; l1 < numberOfPoints; l1++)
        for (int l2 = l1 + 1; l2 < numberOfPoints; l2++)
        {
            Point p1 = pArray[l1], p2 = pArray[l2];
            int x3 = p1.first + p1.second - p2.second;
            int y3 = p1.second - p1.first + p2.first;
            int x4 = p2.first + p1.second - p2.second;
            int y4 = p2.second - p1.first + p2.first;
            if ((pSet.find(Point(x3, y3)) != pSet.end()) && (pSet.find(Point(x4, y4)) != pSet.end()))
                maxArea = std::max(maxArea, pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
        }
    return maxArea;
}