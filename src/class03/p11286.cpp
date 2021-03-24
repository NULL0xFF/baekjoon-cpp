#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

bool compare(std::pair<int, int> &a, std::pair<int, int> &b) { return abs(a.first) < abs(b.first); }

int main(void)
{
    std::vector<std::pair<int, int>> heap;
    int n = 0;
    scanf("%d", &n);
    for (int loop = 0; loop < n; loop++)
    {
        int x = 0;
        scanf("%d", &x);
        if (x == 0)
        {
            if (!heap.empty())
            {
                std::sort(heap.begin(), heap.end(), compare);
                x = heap.begin()->first;
                if (heap.begin()->second == 1)
                    heap.erase(heap.begin());
                else
                    heap.begin()->second--;
            }
            printf("%d\n", x);
        }
        else
        {
            auto it = std::find_if(heap.begin(), heap.end(), [&x](const std::pair<int, int> &element) { return element.first == x; });
            if (it == heap.end())
                heap.push_back(std::make_pair(x, 1));
            else
                it->second++;
        }
    }
    return 0;
}