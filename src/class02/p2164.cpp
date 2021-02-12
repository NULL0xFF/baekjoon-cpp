#include <cstdio>
#include <queue>

int main(void)
{
    int n = 0;
    std::queue<int> list;

    scanf("%d", &n);

    for (int loop = 1; loop <= n; loop++)
        list.push(loop);

    while (list.size() > 1)
    {
        list.pop();
        list.push(list.front());
        list.pop();
    }

    printf("%d", list.front());

    return 0;
}