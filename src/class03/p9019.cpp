#include <iostream>
#include <queue>
#include <string>
#include <utility>

typedef unsigned int uint;

void dslr(void)
{
    uint a = 0, b = 0;
    std::cin >> a >> b;
    // BFS
    bool visited[10000] = {};
    std::queue<std::pair<uint, std::string>> queued;
    queued.push(std::make_pair(a, ""));
    visited[a] = true;
    while (!queued.empty())
    {
        uint num = queued.front().first;
        std::string path = queued.front().second;
        queued.pop();
        if (num == b)
        {
            std::cout << path << "\n";
            return;
        }
        uint changeNum = 0;
        if (visited[changeNum = ((num * 2) % 10000)] == false)
        {
            visited[changeNum] = true;
            queued.push(std::make_pair(changeNum, path + "D"));
        }
        if (visited[changeNum = (num != 0 ? num - 1 : 9999)] == false)
        {
            visited[changeNum] = true;
            queued.push(std::make_pair(changeNum, path + "S"));
        }
        if (visited[changeNum = (((num % 1000) * 10) + (num / 1000))] == false)
        {
            visited[changeNum] = true;
            queued.push(std::make_pair(changeNum, path + "L"));
        }
        if (visited[changeNum = (((num % 10) * 1000) + (num / 10))] == false)
        {
            visited[changeNum] = true;
            queued.push(std::make_pair(changeNum, path + "R"));
        }
    }
    return;
}
int main(void)
{
    uint t = 0;
    std::cin >> t;
    for (uint loop = 0; loop < t; loop++)
        dslr();
    return 0;
}