#include <cstdio>
#include <map>
#include <queue>

class Path
{
public:
    int pos, time;
    Path(int p = 0, int t = 0) : pos(p), time(t) {}
};

int main(void)
{
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);
    /* BFS */
    std::map<int, int> visited;
    std::queue<Path> queued;
    queued.push(Path(n));
    while (!queued.empty())
    {
        Path curPos = queued.front();
        queued.pop();
        auto it = visited.find(curPos.pos);
        if (it != visited.end())
            if (it->second < curPos.time)
                continue;
            else
                it->second = curPos.time;
        visited.emplace(curPos.pos, curPos.time);
        if (curPos.pos == k)
            break;
        if (curPos.pos + 1 <= 100000)
            queued.push(Path(curPos.pos + 1, curPos.time + 1));
        if (curPos.pos - 1 >= 0)
            queued.push(Path(curPos.pos - 1, curPos.time + 1));
        if (curPos.pos * 2 <= 100000)
            queued.push(Path(curPos.pos * 2, curPos.time + 1));
    }
    /* End of BFS */
    printf("%d\n", visited.find(k)->second);
}