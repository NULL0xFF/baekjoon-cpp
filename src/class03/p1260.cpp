#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

void bfs(std::vector<unsigned int> graph[], unsigned int start)
{
    std::vector<unsigned int> visited;
    std::queue<unsigned int> queued;
    queued.push(start);
    while (!queued.empty())
    {
        unsigned int node = queued.front();
        queued.pop();
        if (std::find(visited.begin(), visited.end(), node) != visited.end())
            continue;
        visited.push_back(node);
        for (unsigned int element : graph[node])
            queued.push(element);
    }
    for (unsigned int element : visited)
        printf("%u ", element);
    printf("\n");
    return;
}
void dfs(std::vector<unsigned int> graph[], unsigned int start)
{
    std::vector<unsigned int> visited;
    std::stack<unsigned int> stacked;
    stacked.push(start);
    while (!stacked.empty())
    {
        unsigned int node = stacked.top();
        stacked.pop();
        if (std::find(visited.begin(), visited.end(), node) != visited.end())
            continue;
        visited.push_back(node);
        for (unsigned int element : graph[node])
            stacked.push(element);
    }
    for (unsigned int element : visited)
        printf("%u ", element);
    printf("\n");
    return;
}

int main(void)
{
    unsigned int n = 0, m = 0, s = 0;
    scanf("%u %u %u", &n, &m, &s);
    std::vector<unsigned int> graph[n + 1] = {};
    for (unsigned int loop = 0, a = 0, b = 0; loop < m; loop++)
    {
        scanf("%u %u", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (unsigned int index = 1; index <= n; index++)
        std::sort(graph[index].rbegin(), graph[index].rend());
    dfs(graph, s);
    for (unsigned int index = 1; index <= n; index++)
        std::sort(graph[index].begin(), graph[index].end());
    bfs(graph, s);
    return 0;
}