#include <cstdio>
#include <cmath>
#include <map>

class Element
{
public:
    int num;
    Element(int x) : num(x) {}
    bool operator<(const Element &e) const { return abs(num) == abs(e.num) ? num < e.num : abs(num) < abs(e.num); }
};

bool compare(std::pair<int, int> &a, std::pair<int, int> &b) { return abs(a.first) == abs(b.first) ? a.first < b.first : abs(a.first) < abs(b.first); }

int main(void)
{
    std::map<Element, int> heap;
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
                x = heap.begin()->first.num;
                if (heap.begin()->second == 1)
                    heap.erase(heap.begin());
                else
                    heap.begin()->second--;
            }
            printf("%d\n", x);
        }
        else
        {
            auto it = heap.find(x);
            if (it == heap.end())
                heap.emplace(Element(x), 1);
            else
                it->second++;
        }
    }
    return 0;
}