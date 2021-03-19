#include <cstdio>
#include <utility>

typedef std::pair<int, int> Color;

Color colorPaper(int **data, int x, int y, int size)
{
    int beginData = data[y][x];
    bool isCombinable = true;
    for (int dy = y; dy < y + size && isCombinable == true; dy++)
        for (int dx = x; dx < x + size && isCombinable == true; dx++)
            if (data[dy][dx] != beginData)
                isCombinable = false;
    if (isCombinable)
        return beginData == 0 ? std::make_pair(1, 0) : std::make_pair(0, 1);
    Color ret = std::make_pair(0, 0);
    int mid = size / 2;
    // 1 Up Left
    Color t = colorPaper(data, x, y, mid);
    ret.first += t.first;
    ret.second += t.second;
    // 2 Up Right
    t = colorPaper(data, x + mid, y, mid);
    ret.first += t.first;
    ret.second += t.second;
    // 3 Down Left
    t = colorPaper(data, x, y + mid, mid);
    ret.first += t.first;
    ret.second += t.second;
    // 4 Down Right
    t = colorPaper(data, x + mid, y + mid, mid);
    ret.first += t.first;
    ret.second += t.second;
    return ret;
}

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    int **data = new int *[n]();
    for (int y = 0; y < n; y++)
    {
        data[y] = new int[n]();
        for (int x = 0; x < n; x++)
            scanf("%d", &data[y][x]);
    }
    Color c = colorPaper(data, 0, 0, n);
    printf("%d\n%d\n", c.first, c.second);
    return 0;
}