#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>

int getMode(const int array[], int start, int end)
{
    std::map<int, int> modeMap;
    for (int index = start; index <= end; index++)
    {
        auto it = modeMap.find(array[index]);
        if (it == modeMap.end())
            modeMap.insert(std::make_pair(array[index], 1));
        else
            it->second++;
    }
    int count = 0, mode = 0;
    bool second = false;
    for (auto it : modeMap)
        if (count < it.second)
        {
            count = it.second;
            mode = it.first;
            second = false;
        }
        else if ((count == it.second) && (second == false))
        {
            mode = it.first;
            second = true;
        }
    return mode;
}

int main(void)
{
    int n = 0, sum = 0;
    scanf("%d", &n);
    int array[n + 1] = {};
    for (int index = 1; index <= n; index++)
    {
        scanf("%d", &array[index]);
        sum = sum + array[index];
    }
    printf("%d\n", (int)round((double)sum / (double)n)); // mean
    std::sort(array + 1, array + (n + 1));
    printf("%d\n", array[(int)round((double)n / (double)2)]);
    printf("%d\n", getMode(array, 1, n));
    printf("%d\n", array[n] - array[1]);
    return 0;
}