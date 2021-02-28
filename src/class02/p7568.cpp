#include <cstdio>
#include <utility>

typedef std::pair<int, int> p;

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    p people[n];
    for (int index = 0; index < n; index++)
        scanf("%d %d", &people[index].first, &people[index].second);
    for (int loop = 0; loop < n; loop++)
    {
        int l = 1;
        for (int index = 0; index < n; index++)
            if (people[loop].first < people[index].first && people[loop].second < people[index].second)
                l++;
        printf("%d ", l);
    }
    return 0;
}