/**
 * Baekjoon Online Judge
 * Problem #11725
 * 
 * Input
 * >> L#1: Integer N ( 2 <= N <= 100,000 ), Number of Nodes
 * >> L#2...#N-1: Interger Xn, Yn, Two vertex connected together
 * 
 * Output
 * N/A
 * 
 * Example 1
 * Input
 * >> L#1: 7
 * >> L#2: 1 6
 * >> L#3: 6 3
 * >> L#4: 5 3
 * >> L#5: 4 1
 * >> L#6: 2 4
 * >> L#7: 4 7
 * Output
 * << L#1: 4
 * << L#2: 6
 * << L#3: 1
 * << L#4: 3
 * << L#5: 1
 * << L#6: 4
 * 
 * @author "Ji Myoung Ha"
 */

#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>

int main(int argc, char *argv[])
{
    int numberOfVertex = 0;
    scanf("%d", &numberOfVertex);

    // Create Graph
    std::map<int, std::vector<int> *> graph;
    for (int loop = 0; loop < numberOfVertex; loop++)
        graph.insert(std::make_pair(loop + 1, new std::vector<int>));

    // Input
    int node[2];
    std::vector<int> *list = nullptr;
    for (int loop = 0; loop < numberOfVertex - 1; loop++)
    {
        scanf("%d %d", &node[0], &node[1]);
        list = graph.find(node[0])->second;
        if (std::find(list->begin(), list->end(), node[1]) == list->end())
        {
            list->push_back(node[1]);
            list = graph.find(node[1])->second;
            list->push_back(node[0]);
        }
        else
        {
            return 1; // Key not found
        }
    }

    // DFS
    int *array = new int[numberOfVertex];
    for (int loop = 0; loop < numberOfVertex - 1; loop++)
        array[loop] = 0;
    std::vector<int> visited;
    std::stack<int> stacked;
    node[0] = 1;
    stacked.push(node[0]);
    while (!stacked.empty())
    {
        node[1] = stacked.top();
        stacked.pop();
        if (std::find(visited.begin(), visited.end(), node[1]) == visited.end())
        {
            visited.push_back(node[1]);
            list = graph.find(node[1])->second;
            sort(list->begin(), list->end(), std::greater<int>());
            for (int i = 0; i < (int)list->size(); i++)
            {
                if (array[list->at(i) - 1] == 0)
                    array[list->at(i) - 1] = node[1];
                stacked.push(list->at(i));
            }
        }
    }

    // Output
    for (int loop = 1; loop < numberOfVertex; loop++)
        printf("%d\n", array[loop]);

    return 0;
}