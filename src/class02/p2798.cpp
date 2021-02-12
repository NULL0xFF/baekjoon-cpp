#include <cstdio>
#include <cmath>

int main(void)
{
    int n = 0, m = 0, r = 0;
    int *array = nullptr;

    scanf("%d %d", &n, &m);
    array = new int[n];

    for (int loop = 0; loop < n; loop++)
        scanf("%d", &array[loop]);

    {
        int sum = 0;
        for (int l1 = 0; l1 < n - 2; l1++)
            for(int l2 = l1 + 1; l2 < n - 1; l2++)
                for(int l3 = l2 + 1; l3 < n; l3++)
                {
                    sum = array[l1] + array[l2] + array[l3];
                    if(sum <= m && r < sum)
                        r = sum;
                }
    }
    printf("%d", r);
    return 0;
}