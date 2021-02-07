#include <cstdio>
#include <vector>

int main(void)
{
    std::vector<std::pair<int, char *>> testcaseArr;
    unsigned short testcaseNum = 0;
    unsigned char repeatNum = 0;
    char *stringPtr = nullptr;

    // Input
    scanf("%hud", &testcaseNum);
    for (unsigned short inputLoop = 0; inputLoop < testcaseNum; inputLoop++)
    {
        stringPtr = new char[21];
        scanf("%hhud", &repeatNum);
        scanf("%s", stringPtr);
        testcaseArr.push_back(std::make_pair(repeatNum, stringPtr));
    }

    // Output
    for (unsigned short arrLoop = 0; arrLoop < testcaseNum; arrLoop++)
    {
        repeatNum = testcaseArr[arrLoop].first;
        stringPtr = testcaseArr[arrLoop].second;
        unsigned char stringIndex = 0;
        for (unsigned char stringIndex = 0; stringPtr[stringIndex] != '\0'; stringIndex++)
            for (unsigned char repeatLoop = 0; repeatLoop < repeatNum; repeatLoop++)
                printf("%c", stringPtr[stringIndex]);
        printf("\n");
    }

    return 0;
}