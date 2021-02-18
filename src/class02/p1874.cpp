#include <cstdio>
#include <stack>
#include <queue>

int main(void)
{
    std::stack<int> s;
    std::queue<char> q;
    int *inputArray = nullptr;
    int n = 0;

    scanf("%d", &n);
    inputArray = new int[n]();
    for (int loop = 0; loop < n; loop++)
        scanf("%d", &inputArray[loop]);

    {
        int offset = 0;
        for (int loop = 1; loop <= n; loop++)
        {
            s.push(loop);
            q.push('+');
            while (!s.empty() && s.top() == inputArray[offset])
            {
                s.pop();
                q.push('-');
                offset++;
            }
        }
    }

    if (!s.empty())
        printf("NO\n");
    else
        while(!q.empty())
        {
            printf("%c\n", q.front());
            q.pop();
        }
    return 0;
}