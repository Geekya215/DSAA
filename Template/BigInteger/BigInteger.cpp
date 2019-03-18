#include <string>
#include <iostream>
#include "BigInteger.h"


// constructure
BigInteger::BigInteger() {

}

BigInteger::BigInteger(long long number) {
    num.clear();

    do {
        num.push_back(number%10+'0');
        number /= 10;
    } while(number);
}


BigInteger::BigInteger(const std::string& number) {
    num.clear();
    int len = number.size();
    for(int i = len-1; ~i; --i) {
        num.push_back(number[i]);
    }
}

//-------------------------------------

BigInteger BigInteger::operator = (long long number) {
    return BigInteger(number);
}

BigInteger BigInteger::operator = (const std::string& number) {
    return BigInteger(number);
}


BigInteger BigInteger::operator + (const BigInteger& b) {
    BigInteger ans;
    auto ita = num.begin();
    auto itb = b.num.begin();
    int temp = 0;

    while(ita!=num.end() && itb!=b.num.end()) {
        temp += *ita-'0' + *itb-'0';
        ans.num.push_back(temp%10+'0');
        temp /= 10;
        ++ita;
        ++itb;
    }

    auto itc = ita==num.end()?itb:ita;
    auto itd = ita==num.end()?b.num.end():num.end();

    while(itc != itd) {
        temp += *itc-'0';
        ans.num.push_back(temp%10+'0');
        temp /= 10;
        ++itc;
    }

    while(temp) {
        ans.num.push_back(temp%10+'0');
        temp/=10;
    }

    return ans;
}

std::ostream& operator << (std::ostream& out, const BigInteger& number) {
    long long len = number.num.size()-1;
    while(~len) {
        out << number.num[len];
        len--;
    }
}


int main() {
    BigInteger a = 1213131;
    BigInteger b = 123;
    std::cout << a+b << std::endl;
}