/**
 * 문제
 * N(1 ≤ N ≤ 100,000)개의 정수들이 있을 때,
 * a번째 정수부터 b번째 정수까지 중에서 제일 작은 정수,
 * 또는 제일 큰 정수를 찾는 것은 어려운 일이 아니다.
 * 하지만 이와 같은 a, b의 쌍이 M(1 ≤ M ≤ 100,000)개 주어졌을 때는 어려운 문제가 된다.
 * 이 문제를 해결해 보자.
 * 여기서 a번째라는 것은 입력되는 순서로 a번째라는 이야기이다.
 * 예를 들어 a=1, b=3이라면 입력된 순서대로 1번, 2번, 3번 정수 중에서 최소, 최댓값을 찾아야 한다.
 * 각각의 정수들은 1이상 1,000,000,000이하의 값을 갖는다.
 * 
 * 입력
 * 첫째 줄에 N, M이 주어진다. 다음 N개의 줄에는 N개의 정수가 주어진다. 다음 M개의 줄에는 a, b의 쌍이 주어진다.
 * 
 * 출력
 * M개의 줄에 입력받은 순서대로 각 a, b에 대한 답을 최솟값, 최댓값 순서로 출력한다.
 */

#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

int main(int argc, char *argv[])
{
    // Variables
    int n = 0, m = 0;
    std::vector<long int> inputList;
    std::vector<std::pair<long int, long int>> searchList;
    std::vector<long int> outputList;

    // Input
    scanf("%d %d", &n, &m);

    // Input N
    for (int l = 0; l < n; l++)
    {
        long int li = 0;
        scanf("%ld", &li);
        inputList.push_back(li);
    }

    // Input M
    for (int l = 0; l < m; l++)
    {
        long int a, b;
        scanf("%ld %ld", &a, &b);
        searchList.push_back(std::pair<long int, long int>(a, b));
    }
    // Sort
    std::sort(inputList.begin(), inputList.end());

    // Search
    

    // Output

    // Debug
    for (int l = 0; l < n; l++)
        printf("%ld ", inputList.at(l));
    printf("\n");
    for (int l = 0; l < m; l++)
        printf("(%ld %ld) ", searchList.at(l).first, searchList.at(l).second);
    printf("\n");

    return 0;
}