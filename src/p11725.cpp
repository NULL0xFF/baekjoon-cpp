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
#include <map>
#include <vector>

int main(int argc, char *argv[])
{
    int numberOfVertex = 0;
    scanf("%d", &numberOfVertex);

    std::map<int, std::vector<int> *> hashMap;

    
    for (int loop = 0; loop < numberOfVertex - 1; loop++)
    {
    }
    return 0;
}