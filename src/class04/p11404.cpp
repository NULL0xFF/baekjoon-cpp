#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

//int dijkstra(std::vector<std::pair<int, int>> graph[], int graphSize, int departure, int arrival);

/* 
 * Sudo Code
 * 
 function Dijkstra(Graph, source):
    dist[source] := 0
    for each vertex v in Graph:
        if v != source
            dist[v] := infinity
        add v to Q
    
    while Q is not empty:
        v := vertex in Q with min dist[v]
        remove v from Q

        for each neighbor u of v:
            alt := dist[v] + length(v, u)
            if alt < dist[u]:
                dist[u] := alt
    return dist[]
end function
 */
int dijkstra(std::vector<std::pair<int, int>> graph[], int source)
{
    std::vector<std::pair<int, int>> dist;
    std::set<int> Q;
    for (auto vertex : graph[source])
    {
        /*
         * vertex.first is arrival city
         * vertex.second is cost
         */
        if (vertex.first != source)
            dist.push_back(std::make_pair(vertex.first, -1));
        Q.insert(vertex.first);
    }
    int minNode;
    int minNodeDistance;
    int altDistance;
    while (!Q.empty())
    {
        minNode = -1;
        minNodeDistance = -1;
        for (int node : Q)
        {
            auto distNode = std::find_if(dist.begin(),
                                         dist.end(),
                                         [&node](const std::pair<int, int> &element) { return element.first == node; });
            if (minNodeDistance == -1 ||
                distNode->second < minNodeDistance)
            {
                minNode = node;
                minNodeDistance = distNode->second;
            }
        }
        Q.erase(minNode);

        std::vector<std::pair<int, int>> minNodeMap = graph[minNode];
        for(auto it : minNodeMap) {
            if(Q.find(it.first) != Q.end()) {
                altDistance = minNodeDistance + it.second;
                auto distNode = std::find_if(dist.begin(),
                                         dist.end(),
                                         [&it](const std::pair<int, int> &element) { return element.first == it.first; });
                if(distNode->second == -1 || altDistance < distNode->second)
                {
                    distNode->second = altDistance;
                }

            }
        }
    }
    return -1;
}

int main(void)
{
    int n = 0; // Number of Cities
    int m = 0; // Number of Buses

    scanf("%d", &n);
    scanf("%d", &m);

    std::vector<std::pair<int, int>> graph[n];

    {
        int d = 0, a = 0, c = 0;
        for (int loop = 0; loop < m; loop++)
        {
            scanf("%d %d %d", &d, &a, &c); // Departure, Arrival, Cost
            graph[d - 1].push_back(std::make_pair(a - 1, c));
        }
    }

    for (int loop = 0; loop < n; loop++)
    {
        printf("[Departure (%d)]\n", loop + 1);
        for (auto it = graph[loop].begin(); it != graph[loop].end(); it++)
        {
            printf("%d -> %d, %d\n", loop + 1, it->first + 1, it->second);
        }
    }

    for (int d = 0; d < n; d++)
    {
        for (int a = 0; a < n; a++)
        {
            printf("%d ", dijkstra(graph, d, a));
        }
        printf("\n");
    }

    return 0;
}
/*
int dijkstra(std::vector<std::pair<int, int>> graph[],
             int graphSize,
             int departure,
             int arrival)
{
    // Initialize
    std::vector<std::pair<int, int>> distanceGraph;
    std::vector<std::pair<int, int>> previousPath;
    std::set<int> Q;

    // Set-Up
    distanceGraph.push_back(std::make_pair(departure, 0));
    previousPath.push_back(std::make_pair(departure, -1));
    for (auto it = graph[departure].begin(); it != graph[departure].end(); it++)
    {
        if (it->first != departure)
        {
            distanceGraph.push_back(std::make_pair(it->first, it->second));
            previousPath.push_back(std::make_pair(it->first, -1));
        }
        Q.insert(it->first);
    }

    // Loop
    int fastestNode;
    int fastestNodeDistance;
    int alternativeNodeDistance;
    while (!Q.empty())
    {
        fastestNode = -1;
        fastestNodeDistance = -1;
        for (const int &node : Q)
        {
            if (distanceGraph[node].second < fastestNodeDistance ||
                fastestNodeDistance == -1)
            {
                fastestNode = node;
                fastestNodeDistance = distanceGraph[node].second;
            }
        }
        Q.erase(fastestNode);

        graph[fastestNode];
        for(auto it = graph[fastestNode].begin(); it != graph[fastestNode].end(); it++)
        {
            if(Q.find(it->first) != Q.end())
            {
                alternativeNodeDistance = fastestNodeDistance + graph[fastestNode].at(it->first);
                if(alternativeNodeDistance < distanceGraph[it->first].second)
                {
                    distanceGraph[it->first].second = alternativeNodeDistance;
                    previousPath.push_back(std::make_pair(it->first, fastestNode));
                }
            }
        }
    }
}
*/