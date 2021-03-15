/* 
 * 네 개의 명령어 D, S, L, R 을 이용하는 간단한 계산기가 있다.
 * 이 계산기에는 레지스터가 하나 있는데, 이 레지스터에는 0 이상 10,000 미만의 십진수를 저장할 수 있다.
 * 각 명령어는 이 레지스터에 저장된 n을 다음과 같이 변환한다.
 * n의 네 자릿수를 d1, d2, d3, d4라고 하자(즉 n = ((d1 × 10 + d2) × 10 + d3) × 10 + d4라고 하자)
 * 
 * 1.   D: D 는 n을 두 배로 바꾼다. 결과 값이 9999 보다 큰 경우에는 10000 으로 나눈 나머지를 취한다.
 *      그 결과 값(2n mod 10000)을 레지스터에 저장한다.
 * 2.   S: S 는 n에서 1 을 뺀 결과 n-1을 레지스터에 저장한다.
 *      n이 0 이라면 9999 가 대신 레지스터에 저장된다.
 * 3.   L: L 은 n의 각 자릿수를 왼편으로 회전시켜 그 결과를 레지스터에 저장한다.
 *      이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d2, d3, d4, d1이 된다.
 * 4.   R: R 은 n의 각 자릿수를 오른편으로 회전시켜 그 결과를 레지스터에 저장한다.
 *      이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d4, d1, d2, d3이 된다.
 * 
 * 위에서 언급한 것처럼, L 과 R 명령어는 십진 자릿수를 가정하고 연산을 수행한다.
 * 예를 들어서 n = 1234 라면 여기에 L 을 적용하면 2341 이 되고 R 을 적용하면 4123 이 된다.
 * 
 * 여러분이 작성할 프로그램은 주어진 서로 다른 두 정수 A와 B(A ≠ B)에 대하여 A를 B로 바꾸는 최소한의 명령어를 생성하는 프로그램이다.
 * 예를 들어서 A = 1234, B = 3412 라면 다음과 같이 두 개의 명령어를 적용하면 A를 B로 변환할 수 있다.
 * 
 * 1234 →L 2341 →L 3412
 * 1234 →R 4123 →R 3412
 * 
 * 따라서 여러분의 프로그램은 이 경우에 LL 이나 RR 을 출력해야 한다.
 * 
 * n의 자릿수로 0 이 포함된 경우에 주의해야 한다.
 * 예를 들어서 1000 에 L 을 적용하면 0001 이 되므로 결과는 1 이 된다.
 * 그러나 R 을 적용하면 0100 이 되므로 결과는 100 이 된다.
 */
/* 
 * 3
 * 1234 3412
 * 1000 1
 * 1 16
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <utility>
typedef unsigned int uint;
typedef std::pair<uint, std::string> container;
uint fnD(const uint n) { return (n * 2) % 10000; }
uint fnS(const uint n) { return n != 0 ? n - 1 : 9999; }
uint fnL(const uint n) { return (((n / 100) % 10) * 1000) + (((n / 10) % 10) * 100) + ((n % 10) * 10) + (n / 1000); }
uint fnR(const uint n) { return ((n % 10) * 1000) + ((n / 1000) * 100) + (((n / 100) % 10) * 10) + ((n / 10) % 10); }
void dslr(void)
{
    uint a = 0, b = 0;
    std::cin >> a >> b;
    // BFS
    std::vector<uint> visited;
    std::queue<container> queued;
    queued.push(container(a, ""));
    container con = {0, ""};
    while (!queued.empty())
    {
        con = queued.front();
        queued.pop();
        if (con.first == b)
            break;
        if (std::find(visited.begin(), visited.end(), con.first) == visited.end())
        {
            visited.push_back(con.first);
            queued.push(container(fnD(con.first), con.second + 'D'));
            queued.push(container(fnS(con.first), con.second + 'S'));
            queued.push(container(fnL(con.first), con.second + 'L'));
            queued.push(container(fnR(con.first), con.second + 'R'));
        }
    }
    std::cout << con.second << "\n";
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