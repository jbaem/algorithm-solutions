#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>

#define MOD 1000000000

using namespace std;

int N, res = 0, dp[101][10][4];

void make_dp_array() {
    for (int i = 1; i < 9; ++i) {
        dp[1][i][0] = 1;
    }
    dp[1][9][2] = 1;

    for (int seq = 2; seq <= N; ++seq) {
        for (int curr = 0; curr < 10; ++curr) {
            for (int k = 0; k < 4; ++k) {
                int flag = k;
                if (curr == 0) flag |= 1;
                if (curr == 9) flag |= 2;
                
                if (curr != 0) {
                    dp[seq][curr][flag] += dp[seq - 1][curr - 1][k];
                    dp[seq][curr][flag] %= MOD;
                }
                if (curr != 9) {
                    dp[seq][curr][flag] += dp[seq - 1][curr + 1][k];
                    dp[seq][curr][flag] %= MOD;
                }
            }
        }
    }
}

int main() {
    fastio();

    cin >> N;    
    make_dp_array();
    
    for (int i = 0; i < 10; ++i) {
        res += dp[N][i][3];
        res %= MOD;
    }
    cout << res;
    return 0;
}