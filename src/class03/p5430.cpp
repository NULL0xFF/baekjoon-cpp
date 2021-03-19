#include <cstdio>
#include <deque>

std::deque<int> *tokenizer(char *array)
{
    std::deque<int> *ret = new std::deque<int>();
    int index = 0, token = -1;
    while (array[index] != '\0')
    {
        if (array[index] == ',')
        {
            ret->push_back(token);
            token = -1;
        }
        else if (array[index] == '[')
        {
            index++;
            continue;
        }
        else if (array[index] == ']')
        {
            if (token == -1)
                break;
            ret->push_back(token);
            break;
        }
        else if (token == -1)
            token = array[index] - '0';
        else
            token = (token * 10) + (array[index] - '0');
        index++;
    }
    return ret;
}

void languageAC(void)
{
    int n = 0;
    char command[100000] = "";
    char arrayString[500000] = "";
    bool rev = false;
    scanf(" %s", command);
    scanf("%d", &n);
    scanf(" %s", arrayString);
    std::deque<int> *array = tokenizer(arrayString);

    /* Operation */
    for (int index = 0; index < 100000; index++)
    {
        if (command[index] == 'R')
            rev = (rev == false ? true : false);
        else if (command[index] == 'D')
        {
            if (array->empty())
            {
                printf("error\n");
                return;
            }
            if (rev == false)
                array->pop_front();
            else
                array->pop_back();
        }
        else
            break;
    }
    /* Operation */
    /* Output */
    printf("[");
    while (!array->empty())
    {
        if (rev == false)
        {
            printf("%d", array->front());
            array->pop_front();
        }
        else
        {
            printf("%d", array->back());
            array->pop_back();
        }
        if (!array->empty())
            printf(",");
    }
    printf("]\n");
    /* Output */
    return;
}
int main(void)
{
    int testCase = 0;
    scanf("%d", &testCase);
    for (int loop = 0; loop < testCase; loop++)
        languageAC();
    return 0;
}