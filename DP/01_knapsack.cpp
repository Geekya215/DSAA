#include <iostream>

const int size = 1e2+5; // max range (default)
int v[size]; // value of every stuff
int c[size]; // capacity of evert stuff
// int dp[size][size]; // default method
int dp[size]; // space optimize
int n; // amount of stuff
int m; // knapsack capacity


int main() {
    std::cin >> n >> m;
    for(int i = 1; i <= n; ++i) 
        std::cin >> v[i] >> c[i];

    // default
    // for(int i = 1; i <= n; ++i) {
    //     for(int j = 1; j <= m; ++j) {
    //         if(j<c[i])
    //             dp[i][j] = dp[i-1][j];
    //         else
    //             dp[i][j] = std::max(dp[i-1][j],dp[i-1][j-c[i]]+v[i]);
    //     }
    // }

    // space optimize
    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= 0; --j) {
            if(j >= c[i])
                dp[j] = std::max(dp[j],dp[j-c[i]]+v[i]);
        }
    }

    // std::cout << dp[n][m] << std::endl;
    std::cout << dp[m] << std::endl;
    return 0;
}