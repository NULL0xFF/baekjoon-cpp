#include <cstdio>
#include <map>

int main(void)
{
    std::map<unsigned int, unsigned int> heap;
    int n = 0;
    scanf("%d", &n);
    for (int loop = 0; loop < n; loop++)
    {
        unsigned int x = 0;
        scanf("%u", &x);
        if (x == 0)
        {
            if (!heap.empty())
            {
                x = heap.begin()->first;
                if (heap.begin()->second == 1)
                    heap.erase(heap.begin()->first);
                else
                    heap.begin()->second--;
            }
            printf("%d\n", x);
        }
        else
        {
            auto it = heap.find(x);
            if (it == heap.end())
                heap.emplace(x, 1);
            else
                it->second++;
        }
    }
    return 0;
}