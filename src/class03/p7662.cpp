#include <cstdio>
#include <map>

int main(void)
{
    int t = 0;
    scanf("%d", &t);
    for (int test = 0; test < t; test++)
    {
        int k = 0;
        scanf("%d", &k);
        {
            std::map<int, int> Q;
            int n = 0;
            char c = '\0';
            for (int loop = 0; loop < k; loop++)
            {
                scanf(" %c %d", &c, &n);
                if (c == 'I')
                {
                    auto it = Q.find(n);
                    if (it == Q.end())
                        Q.emplace(n, 1);
                    else
                        it->second++;
                }
                else if (c == 'D')
                    if (!Q.empty())
                        if (n == 1)
                            if (Q.rbegin()->second == 1)
                                Q.erase(Q.rbegin()->first);
                            else
                                Q.rbegin()->second--;
                        else if (n == -1)
                            if (Q.begin()->second == 1)
                                Q.erase(Q.begin()->first);
                            else
                                Q.begin()->second--;
            }
            if (Q.empty())
                printf("EMPTY\n");
            else
                printf("%d %d\n", Q.rbegin()->first, Q.begin()->first);
        }
    }
    return 0;
}