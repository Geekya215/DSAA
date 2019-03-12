#include <iostream>

/**
 * Fast way to calculate week give any date
 * 
 * Explain for marks:
 * C:Century - 1
 * Y:Year of the century
 * M:Month of the year(Jan and Feb are counted as month 13 and 14 last year)
 * D:Day of the month
 * 
 * Note:1. if W is negetive we should make it be positive and mod it
 *      2. 0 is represent Sunday, an so on. 
 **/

int zeller(int year, int month, int day) {
    if(month < 3) {
        year--;
        month += 12;
    }
    int W;
    int C = year/100;
    int Y = year%100;
    int M = month;
    int D = day;

    W = Y + Y/4 + C/4 - 2*C + 26*(M+1)/10 + D - 1;
    W = W<0 ? (W+(-W/7+1)*7):W;
    return W%7;
}


int main() {
    int y,m,d;
    std::cin >> y >> m >> d;
    std::cout << zeller(y,m,d) << std::endl;
    return 0;
}