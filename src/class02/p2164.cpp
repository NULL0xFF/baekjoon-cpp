#include <cstdio>
#include <queue>

int sol2(void)
{
    int n = 0;
    int* array = nullptr;

    scanf("%d", &n);
    array = new int[n * 2]();

    for (int loop = 0; loop < n; loop++)
        array[loop] = loop + 1;


    int frontPtr = 0;
    int endPtr = n;
    while (frontPtr + 1 < endPtr)
    {
        frontPtr++;
        array[endPtr] = array[frontPtr];
        frontPtr++;
        endPtr++;
    }

    printf("%d", array[frontPtr]);

    return 0;
}

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