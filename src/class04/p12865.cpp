#include <cstdio>

int max(int a, int b) { return a > b ? a : b; }

int main(void)
{
    int numberOfItems = 0, capacity = 0;
    scanf("%d %d", &numberOfItems, &capacity);
    int weight[numberOfItems + 1] = {};
    int value[numberOfItems + 1] = {};
    for (int index = 1; index <= numberOfItems; index++)
        scanf("%d %d", &weight[index], &value[index]);
    int data[numberOfItems + 1][capacity + 1] = {};
    for (int i = 1; i <= numberOfItems; i++)
        for (int j = 0; j <= capacity; j++)
            if (weight[i] > j)
                data[i][j] = data[i - 1][j];
            else
                data[i][j] = max(data[i - 1][j], data[i - 1][j - weight[i]] + value[i]);
    printf("%d\n", data[numberOfItems][capacity]);
    return 0;
}