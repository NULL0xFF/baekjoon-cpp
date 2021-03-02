#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

bool compare(const char a[], const char b[]) { return strcmp(a, b) < 0; }

bool search(char *array[], int start, int end, char target[])
{
    if (start > end)
        return false;
    int mid = (start + end) / 2;
    int flag = strcmp(array[mid], target);
    if (flag == 0)
        return true;
    else if (flag < 0)
        return search(array, mid + 1, end, target);
    else
        return search(array, start, mid - 1, target);
}

int main(void)
{
    char **listen = nullptr, **observe = nullptr;
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    listen = new char *[n]();
    observe = new char *[m]();
    for (int loop = 0; loop < n; loop++)
    {
        listen[loop] = new char[21]();
        scanf(" %s", listen[loop]);
    }
    for (int loop = 0; loop < m; loop++)
    {
        observe[loop] = new char[21]();
        scanf(" %s", observe[loop]);
    }
    std::sort(listen, listen + n, compare);
    std::sort(observe, observe + m, compare);
    std::queue<int> searched;
    for (int index = 0; index < n; index++)
        if (search(observe, 0, m, listen[index]) == true)
            searched.push(index);
    printf("%d\n", searched.size());
    while (!searched.empty())
    {
        printf("%s\n", listen[searched.front()]);
        searched.pop();
    }
    return 0;
}