#include <cstdio>
#include <cfloat>

#ifdef LDBL_DECIMAL_DIG
#define OP_LDBL_Digs (LDBL_DECIMAL_DIG)
#else
#ifdef DECIMAL_DIG
#define OP_LDBL_Digs (DECIMAL_DIG)
#else
#define OP_LDBL_Digs (LDBL_DIG + 3)
#endif
#endif

int main(void)
{
    unsigned short n;
    scanf("%hud", &n);

    unsigned char max = 0;
    unsigned char input[1000];
    for (unsigned short loop = 0; loop < n; loop++)
    {
        scanf("%hhud", &input[loop]);
        if (max < input[loop])
            max = input[loop];
    }

    long double sum = 0;
    for (unsigned short loop = 0; loop < n; loop++)
        sum = sum + (((long double)input[loop] / (long double)max) * 100);

    sum = sum / (long double)n;

    printf("%.*Lf", OP_LDBL_Digs, sum);

    return 0;
}