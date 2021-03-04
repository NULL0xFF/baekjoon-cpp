#include <cstdio>
#include <cstring>

int main(void)
{
    unsigned int S = 0;
    unsigned int n = 0;
    scanf("%u", &n);
    {
        unsigned int x = 0;
        char op[7] = "";
        for (unsigned int loop = 0; loop < n; loop++)
        {
            scanf(" %s %u", op, &x);
            if (strcmp(op, "add") == 0)
                S |= (1 << x);
            else if (strcmp(op, "remove") == 0)
                S &= ~(1 << x);
            else if (strcmp(op, "check") == 0)
                printf("%u\n", (S >> x) & 1);
            else if (strcmp(op, "toggle") == 0)
                S ^= (1 << x);
            else if (strcmp(op, "all") == 0)
            {
                S = 0;
                for (int i = 1; i <= 20; i++)
                    S |= (1 << i);
            }
            else if (strcmp(op, "empty") == 0)
                S = 0;
        }
    }
    return 0;
}