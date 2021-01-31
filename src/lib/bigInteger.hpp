#ifndef BIGINTEGER_HPP
#define BIGINTEGER_HPP

#include <vector>
#include <string>

class BigInteger
{
private:
    std::vector<int> list;

public:
    BigInteger();
    BigInteger(std::string integerString);
    BigInteger add(BigInteger inputBInt);
    BigInteger sub(BigInteger inputBInt);
    BigInteger mul(BigInteger inputBInt);
    BigInteger div(BigInteger inputBInt);
};

#endif // BIGINTEGER_HPP