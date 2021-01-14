/**
 * Baekjoon Online Judge
 * Problem #11653
 * 
 * Input
 * >> L#1: Integer N ( 1 <= N <= 10,000,000 )
 * 
 * Output
 * Prime Factorization of Integer N
 * Print every one result on one new line in ascending order.
 * Print nothing if N is 1.
 * 
 * Example 1
 * Input
 * >> L#1: 72
 * Output
 * << L#1: 2
 * << L#2: 2
 * << L#3: 2
 * << L#4: 3
 * << L#5: 3
 *  
 * @author "Ji Myoung Ha"
 */

#include <cstdio>

/**
 * Recursive Function
 */
int primeFactorization(int inputNum, int minNum)
{
    int currentNum = inputNum;
    while (true)
    {
        if (currentNum == 1)
            break;
        if (currentNum % minNum == 0)
        {
            printf("%d\n", minNum);
            currentNum = currentNum / minNum;
        }
        else
        {
            primeFactorization(currentNum, minNum + 1);
            break;
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int inputNumber = 0;
    scanf("%d", &inputNumber);

    primeFactorization(inputNumber, 2);

    return 0;
}