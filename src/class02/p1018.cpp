#include <cstdio>

int chessPatternChecker(char **board, int dy, int dx)
{
    int white = 0, black = 0;
    char color = 'W';
    for (int y = dy; y < dy + 8; y++)
    {
        for (int x = dx; x < dx + 8; x++)
        {
            if (board[y][x] != color)
                white++;
            color = color == 'W' ? 'B' : 'W';
        }
        color = color == 'W' ? 'B' : 'W';
    }
    color = 'B';
    for (int y = dy; y < dy + 8; y++)
    {
        for (int x = dx; x < dx + 8; x++)
        {
            if (board[y][x] != color)
                black++;
            color = color == 'W' ? 'B' : 'W';
        }
        color = color == 'W' ? 'B' : 'W';
    }
    return white < black ? white : black;
}

int main(void)
{
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    char **board = new char *[n];
    for (int y = 0; y < n; y++)
    {
        board[y] = new char[m];
        for (int x = 0; x < m; x++)
        {
            scanf(" %c", &board[y][x]);
        }
    }

    int min = n * m;
    int num = 0;
    for (int dy = 0; dy <= n - 8; dy++)
    {
        for (int dx = 0; dx <= m - 8; dx++)
        {
            num = chessPatternChecker(board, dy, dx);
            if (num < min)
                min = num;
        }
    }

    printf("%d", min);

    return 0;
}