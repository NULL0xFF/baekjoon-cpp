#include <cstdio>
#include <algorithm>

typedef unsigned int u_int;
int main(void)
{
    u_int n = 0;
    scanf("%u", &n);
    u_int time[n] = {};
    for (u_int index = 0; index < n; index++)
        scanf("%u", &time[index]);
    std::sort(time, time + n);
    for (u_int index = 1; index < n; index++)
        time[index] = time[index] + time[index - 1];
    u_int total = 0;
    for (u_int index = 0; index < n; index++)
        total += time[index];
    printf("%u\n", total);
    return 0;
}