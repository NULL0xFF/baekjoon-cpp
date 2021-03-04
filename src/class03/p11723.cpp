#include <cstdio>
#include <cstring>
#include <set>

int main(void)
{
    std::set<int> S;
    int n = 0;
    scanf("%d", &n);
    {
        int x = 0;
        char op[7] = "";
        for (int loop = 0; loop < n; loop++)
        {
            scanf(" %s %d", op, &x);
            if (strcmp(op, "add") == 0)
                S.insert(x);
            else if (strcmp(op, "remove") == 0)
                S.erase(x);
            else if (strcmp(op, "check") == 0)
                printf("%d\n", S.find(x) != S.end() ? 1 : 0);
            else if (strcmp(op, "toggle") == 0)
                if (S.find(x) != S.end())
                    S.erase(x);
                else
                    S.insert(x);
            else if (strcmp(op, "all") == 0)
            {
                S.clear();
                for (int i = 1; i <= 20; i++)
                    S.insert(i);
            }
            else if (strcmp(op, "empty") == 0)
                S.clear();
        }
    }
    return 0;
}