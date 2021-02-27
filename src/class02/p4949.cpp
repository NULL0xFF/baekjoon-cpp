#include <iostream>
#include <string>
#include <stack>

bool isParenthesisSymmetrical(const std::string string)
{
    std::stack<char> parenthesis;
    for (int index = 0; index < string.length(); index++)
    {
        switch (string.at(index))
        {
        case '(':
        case '[':
            parenthesis.push(string.at(index));
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
    }
    return parenthesis.empty();
}

int main(void)
{
    // Disable IO Stream Sync
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::string inputString;
    while (true)
    {
        std::getline(std::cin, inputString);
        if (inputString.length() == 1 && inputString.at(0) == '.')
            break;
        if (isParenthesisSymmetrical(inputString))
            std::cout << "yes\n";
        else
            std::cout << "no\n";
    }
    return 0;
}