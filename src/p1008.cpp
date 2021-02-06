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
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%.*Lf", OP_LDBL_Digs, (long double)a / (long double)b);

    return 0;
}