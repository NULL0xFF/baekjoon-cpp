#include <cstdio>

int *cache = nullptr;

int score(int *stair, int start, int end, bool continued)
{
    // Rule 1 (Allow one or two steps at once)
    // Rule 2 (Disallow three steps on series)
    // Rule 3 (Must step on last stair at arrival)

    // Escape
    if (start + 1 == end)
    {
        return stair[start];
    }
    else if (start + 1 > end)
    {
        return -1;
    }

    // Cache
    if (cache[start] != -1)
    {
        return cache[start];
    }

    // // Prepare for arrival
    // if (start + 3 == end)
    // {
    //     if (continued == true)
    //     {
    //         return stair[start] + score(stair, start + 2, end, false);
    //     }
    // }

    int postScore = 0;
    if (continued)
    {
        postScore = score(stair, start + 2, end, false);
    }
    else
    {
        int s1 = score(stair, start + 1, end, true);
        int s2 = score(stair, start + 2, end, false);
        postScore = s1 == -1 ? (s2 == -1 ? -1 : s2) : (s2 == -1 ? s1 : s1 > s2 ? s1
                                                                               : s2);
    }

    if (postScore != -1)
    {
        cache[start] = postScore;
    }

    return postScore == -1 ? -1 : stair[start] + postScore;
}

int main(void)
{
    int n = 0;
    int *stair = nullptr;

    scanf("%d", &n);
    stair = new int[n];
    cache = new int[n];
    for (int i = 0; i < n; i++)
    {
        cache[i] = -1;
        scanf("%d", &stair[i]);
    }

    // DP
    int s1 = score(stair, 0, n, false);
    int s2 = score(stair, 1, n, false);

    printf("%d\n", s1 == -1 ? (s2 == -1 ? -1 : s2) : (s2 == -1 ? s1 : s1 > s2 ? s1
                                                                              : s2));

    return 0;
}