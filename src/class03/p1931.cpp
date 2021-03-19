#include <cstdio>
#include <algorithm>

class Conference
{
public:
    int start, end;
    Conference(int s = 0, int e = 0) : start(s), end(e) {}
    static bool compare(Conference a, Conference b) { return (a.end == b.end) ? a.start < b.start : a.end < b.end; }
};

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    Conference *c = new Conference[n]();
    for (int index = 0; index < n; index++)
        scanf("%d %d", &c[index].start, &c[index].end);
    std::sort(c, c + n, Conference::compare);
    int count = 0, end = 0;
    for (int index = 0; index < n; index++)
        if (end <= c[index].start)
        {
            end = c[index].end;
            count++;
        }
    printf("%d\n", count);
    return 0;
}