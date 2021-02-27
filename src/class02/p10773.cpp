#include <cstdio>
#include <stack>

int main(void)
{
    unsigned int k = 0, input = 0, sum = 0;
    scanf("%ud", &k);
    std::stack<unsigned int> list;
    for (unsigned int loop = 0; loop < k; loop++)
    {
        scanf("%ud", &input);
        if (input == 0)
            list.pop();
        else
            list.push(input);
    }
    while (!list.empty())
    {
        sum = sum + list.top();
        list.pop();
    }
    printf("%u\n", sum);
    return 0;
}