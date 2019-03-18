#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <vector>
#include <string>

class BigInteger {
    public:
        std::vector<char> num;

        BigInteger();

        BigInteger(long long number);

        BigInteger(const std::string& number);

        BigInteger operator = (long long number);

        BigInteger operator = (const std::string& number);

        BigInteger operator + (const BigInteger& b);

        friend std::ostream& operator << (std::ostream& out, const BigInteger& numer);

};

#endif