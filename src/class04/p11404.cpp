#include <cstdio>
#include <vector>
#include <set>

int dijkstra(std::vector<std::pair<int, int>> graph[],
             int graphSize,
             int departure,
             int arrival);

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
            printf("%d ", dijkstra(graph, n, d, a));
        }
        printf("\n");
    }

    return 0;
}

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