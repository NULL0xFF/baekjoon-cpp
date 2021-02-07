#include <cstdio>
#include <vector>
#include <algorithm>

int main(void)
{
    int array[10];
    for (int loop = 0; loop < 10; loop++)
    {
        scanf("%d", &array[loop]);
        array[loop] = array[loop] % 42;
    }
    std::vector<int> remainders;
    for (int loop = 0; loop < 10; loop++)
    {
        if (std::find(remainders.begin(), remainders.end(), array[loop]) == remainders.end())
            remainders.push_back(array[loop]);
    }
    printf("%ld", remainders.size());
    return 0;
}