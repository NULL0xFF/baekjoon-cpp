include <cstdio>

int main(void)
{
        int i = 0;
        scanf("%x", &i);
        if (i == 0)
                printf("0\n");
        else
        {
                while (i != 0)
                {
                        printf("%d", i & 1);
                        i = i >> 1;
                }
                printf("\n");
        }
        return 0;
}
