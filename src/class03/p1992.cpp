#include <cstdio>

void quadTree(char **data, int x, int y, int size)
{
    char beginData = data[y][x];
    bool isCombinable = true;
    for (int dy = y; dy < y + size && isCombinable == true; dy++)
        for (int dx = x; dx < x + size && isCombinable == true; dx++)
            if (data[dy][dx] != beginData)
                isCombinable = false;
    if (isCombinable)
    {
        printf("%c", beginData);
        return;
    }
    int mid = size / 2;
    printf("(");
    // 1 Up Left
    quadTree(data, x, y, mid);
    // 2 Up Right
    quadTree(data, x + mid, y, mid);
    // 3 Down Left
    quadTree(data, x, y + mid, mid);
    // 4 Down Right
    quadTree(data, x + mid, y + mid, mid);
    printf(")");
}

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    char **data = new char *[n]();
    for (int y = 0; y < n; y++)
    {
        data[y] = new char[n]();
        for (int x = 0; x < n; x++)
        {
            char c = '\0';
            scanf("%c", &c);
            if (c == '\n')
            {
                x--;
                continue;
            }
            data[y][x] = c;
        }
    }
    quadTree(data, 0, 0, n);
    return 0;
}