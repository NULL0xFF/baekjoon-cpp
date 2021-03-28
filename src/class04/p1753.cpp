#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <set>

int main(void)
{
    std::map<int, std::map<int, int>> graph;
    int V = 0, E = 0, S = 0;
    scanf("%d %d", &V, &E);
    scanf("%d", &S);
    for (int loop = 0; loop < E; loop++)
    {
        int u = 0, v = 0, w = 0;
        scanf("%d %d %d", &u, &v, &w);
        auto it = graph.find(u);
        if (graph.find(u) == graph.end())
            graph.emplace(u, std::map<int, int>());
        it = graph.find(u);
        auto it2 = it->second.find(v);
        if (it2 == it->second.end())
            it->second.emplace(v, w);
        else if (w < it2->second)
            it2->second = w;
    }
    /* Dijkstra */
    std::map<int, int> dist;
    std::set<int> Q;
    for (int v = 1; v <= V; v++)
    {
        dist.emplace(v, -1);
        Q.insert(v);
    }
    dist[S] = 0;
    /* Loop */
    int minNode;
    int minNodeDistance;
    int altDistance = 0;
    while (!Q.empty())
    {
        minNode = -1;
        minNodeDistance = -1;
        for (int node : Q)
            if ((dist[node] >= 0 && dist[node] < minNodeDistance) || minNodeDistance == -1)
            {
                minNode = node;
                minNodeDistance = dist[node];
            }
        Q.erase(minNode);
        std::map<int, int> minNodeMap = graph[minNode];
        for (auto it : minNodeMap)
            if (Q.find(it.first) != Q.end())
            {
                altDistance = minNodeDistance + it.second;
                if (altDistance < dist[it.first] || dist[it.first] == -1)
                    dist[it.first] = altDistance;
            }
    }
    /* End of Loop */
    /* End of Dijkstra */
    for (int v = 1; v <= V; v++)
        if (dist[v] == -1)
            printf("INF\n");
        else
            printf("%d\n", dist[v]);
    return 0;
}