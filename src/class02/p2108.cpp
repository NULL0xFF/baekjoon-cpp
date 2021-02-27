#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>

int getMean(const int array[], int start, int end)
{
    int sum = 0;
    for (int index = start - 1; index < end; index++)
        sum = sum + array[index];
    int result = sum / (end - start + 1);
    if ((abs(sum) - abs(result * (end - start + 1)) >= 0.5) && sum < 0)
        result = result - 1;
    return result;
}
int getMedian(const int array[], int start, int end)
{
    return array[(end + start) / 2 - 1];
}
int getMode(const int array[], int start, int end)
{
    std::map<int, int> modeMap;
    for (int index = start - 1; index < end; index++)
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
int getRange(const int array[], int start, int end)
{
    return array[end - 1] - array[start - 1];
}

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    int array[n] = {};
    for (int loop = 0; loop < n; loop++)
        scanf("%d", &array[loop]);
    std::sort(array, array + n);
    printf("%d\n", getMean(array, 1, n));
    printf("%d\n", getMedian(array, 1, n));
    printf("%d\n", getMode(array, 1, n));
    printf("%d\n", getRange(array, 1, n));
    return 0;
}