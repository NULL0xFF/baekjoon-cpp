#include <cstdio>

int main(void)
{
    short a, b;
    scanf("%hd %hd", &a, &b);
    printf("%s", (a > b) ? ">" : ((a < b) ? "<" : "=="));
}