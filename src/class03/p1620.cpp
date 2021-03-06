#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>

typedef std::pair<char *, int> P;

int parseInt(char str[])
{
    bool isPositive = true;
    int index = 0, result = 0;
    if (str[0] == '-')
    {
        isPositive = false;
        index++;
    }
    else if (str[0] == '+')
        index++;
    while (str[index] != '\0')
    {
        if (str[index] < '0' || str[index] > '9')
            return -1;
        result = (result * 10) + (str[index] - '0');
        index++;
    }
    return isPositive ? result : result * -1;
}

int binarySearch(P array[], int start, int end, char target[])
{
    if (start > end)
        return -1;
    int mid = (start + end) / 2;
    int i = strcmp(array[mid - 1].first, target);
    if (i == 0)
        return array[mid - 1].second;
    else if (i < 0)
        return binarySearch(array, mid + 1, end, target);
    else
        return binarySearch(array, start, mid - 1, target);
}

bool compare(P &a, P &b)
{
    int i = strcmp(a.first, b.first);
    if (i < 0)
        return true;
    else if (i == 0)
        return a.second < b.second;
    return false;
}

int main(void)
{
    int n = 0, m = 0, i = 0;
    char input[21] = "";
    scanf("%d %d", &n, &m);
    char **string = new char *[n]();
    P book[n];
    for (int index = 0; index < n; index++)
    {
        string[index] = new char[21]();
        book[index] = {new char[21](), index};
        scanf(" %s", string[index]);
        book[index].first = string[index];
    }
    std::sort(book, book + n, compare);
    for (int loop = 0; loop < m; loop++)
    {
        scanf(" %s", input);
        i = parseInt(input);
        if (i == -1)
            printf("%d\n", binarySearch(book, 1, n, input) + 1);
        else
            printf("%s\n", string[i - 1]);
    }
    return 0;
}