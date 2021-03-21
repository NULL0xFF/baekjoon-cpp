#include <cstdio>
#include <algorithm>
#include <vector>

class Item
{
public:
    int weight, value;
    Item(int w = 0, int v = 0) : weight(w), value(v) {}
};

int main(void)
{
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);
    Item items[n + 1] = {};
    int **data = new int *[n + 1]();
    for (int index = 0; index <= n; index++)
        data[index] = new int[k + 1]();
    for (int index = 1; index <= n; index++)
    {
        scanf("%d %d", &items[index].weight, &items[index].value);
    }
    for (int w = 0; w <= k; w++)
        data[0][w] = 0;
    for (int i = 1; i <= n; i++)
        data[i][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int w = 0; w <= k; w++)
            if (items[i].weight <= w)
                if (items[i].value + data[i - 1][w - items[i].weight] > data[i - 1][w])
                    data[i][w] = items[i].value + data[i - 1][w - items[i].weight];
                else
                    data[i][w] = data[i - 1][w];
            else
                data[i][w] = data[i - 1][w];
    std::vector<int> selected;
    while (n > 0 && k > 0)
    {
        if (data[n][k] != data[n - 1][k])
        {
            selected.push_back(n);
            n--;
            k = k - items[n].weight;
        }
        else
        {
            n--;
        }
    }
    printf("done");
    return 0;
}