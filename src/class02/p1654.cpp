#include <cstdio>

int main(void)
{
    int k, n;
    scanf("%d %d", &k, &n);

    int *arr = new int[k]();
    for (int loop = 0; loop < k; loop++)
        scanf("%d", &arr[loop]);

    int min = -1;
    for (int loop = 0; loop < k; loop++)
        if (min == -1)
            min = arr[loop];
        else if (arr[loop] < min)
            min = arr[loop];
    
    

    return 0;
}