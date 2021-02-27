#include <cstdio>
#include <stack>

bool isParenthesisSymmetrical(const char *string)
{
    std::stack<char> parenthesis;
    int index = 0;
    while (string[index] != '\0')
    {
        switch (string[index])
        {
        case '(':
        case '[':
            parenthesis.push(string[index]);
            break;
        case ')':
            if (parenthesis.empty())
                return false;
            else if (parenthesis.top() != '(')
                return false;
            parenthesis.pop();
            break;
        case ']':
            if (parenthesis.empty())
                return false;
            else if (parenthesis.top() != '[')
                return false;
            parenthesis.pop();
            break;
        }
        index++;
    }
    return parenthesis.empty();
}

int main(void)
{
    char string[101] = "";
    while (true)
    {
        for (int index = 0; index < 100; index++)
        {
            string[index] = getchar();
            if (string[index] == '\n')
                string[index] = '\0';
            if (string[index] == '\0')
                break;
        }
        if (string[0] == '.' && string[1] == '\0')
            break;
        printf("%s\n", isParenthesisSymmetrical(string) ? "yes" : "no");
    }
    return 0;
}