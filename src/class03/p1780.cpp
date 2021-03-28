#include <cstdio>

class Color
{
public:
    int minus, zero, plus;
    Color(int m = 0, int z = 0, int p = 0) : minus(m), zero(z), plus(p) {}
};

Color colorPaper(int **data, int x, int y, int size)
{
    int beginData = data[y][x];
    bool isCombinable = true;
    for (int dy = y; dy < y + size && isCombinable == true; dy++)
        for (int dx = x; dx < x + size && isCombinable == true; dx++)
            if (data[dy][dx] != beginData)
                isCombinable = false;
    if (isCombinable)
        return beginData == -1 ? Color(1, 0, 0) : beginData == 0 ? Color(0, 1, 0)
                                                                 : Color(0, 0, 1);
    Color ret;
    int mSize = size / 3;
    // 1 Up Left
    Color t = colorPaper(data, x, y, mSize);
    ret.minus += t.minus;
    ret.zero += t.zero;
    ret.plus += t.plus;
    // 2 Up
    t = colorPaper(data, x + mSize, y, mSize);
    ret.minus += t.minus;
    ret.zero += t.zero;
    ret.plus += t.plus;
    // 3 Up Right
    t = colorPaper(data, x + (mSize * 2), y, mSize);
    ret.minus += t.minus;
    ret.zero += t.zero;
    ret.plus += t.plus;
    // 4 Left
    t = colorPaper(data, x, y + mSize, mSize);
    ret.minus += t.minus;
    ret.zero += t.zero;
    ret.plus += t.plus;
    // 5 Mid
    t = colorPaper(data, x + mSize, y + mSize, mSize);
    ret.minus += t.minus;
    ret.zero += t.zero;
    ret.plus += t.plus;
    // 6 Right
    t = colorPaper(data, x + (mSize * 2), y + mSize, mSize);
    ret.minus += t.minus;
    ret.zero += t.zero;
    ret.plus += t.plus;
    // 7 Down Left
    t = colorPaper(data, x, y + (mSize * 2), mSize);
    ret.minus += t.minus;
    ret.zero += t.zero;
    ret.plus += t.plus;
    // 8 Down
    t = colorPaper(data, x + mSize, y + (mSize * 2), mSize);
    ret.minus += t.minus;
    ret.zero += t.zero;
    ret.plus += t.plus;
    // 9 Down Right
    t = colorPaper(data, x + (mSize * 2), y + (mSize * 2), mSize);
    ret.minus += t.minus;
    ret.zero += t.zero;
    ret.plus += t.plus;
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
    printf("%d\n%d\n%d\n", c.minus, c.zero, c.plus);
    return 0;
}