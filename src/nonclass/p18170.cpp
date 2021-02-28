#include <cstdio>

struct Coin
{
    int x = -1, y = -1;
};

int main(void)
{
    // Variables
    Coin c1, c2;
    char **board = nullptr;
    int n = 0, m = 0;

    // Input
    scanf("%d %d", &n, &m);
    board = new char *[n]();
    for (int y = 0; y < n; y++)
    {
        board[y] = new char[m]();
        for (int x = 0; x < m; x++)
        {
            char c = '\0';
            scanf(" %c", &c);
            if (c == 'o')
                if (c1.x == -1 && c1.y == -1)
                {
                    c1.x = x;
                    c1.y = y;
                }
                else if (c2.x == -1 && c2.y == -1)
                {
                    c2.x = x;
                    c2.y = y;
                }
            board[y][x] = c;
        }
    }
    

    // Output
    return 0;
}