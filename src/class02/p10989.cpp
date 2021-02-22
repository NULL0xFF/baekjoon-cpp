#include <cstdio>

int main(void)
{
    int *array = new int[10000]();
    int n = 0;
    scanf("%d", &n);
    for (int loop = 0, input = 0; loop < n; loop++)
    {
        scanf("%d", &input);
        array[input - 1]++;
    }
    for (int index = 0; index < 10000; index++)
        if (array[index] != 0)
            for (int loop = 0; loop < array[index]; loop++)
                printf("%d\n", index + 1);
    return 0;
}