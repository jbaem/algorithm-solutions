#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, T;
vector<vector<int>> dp;
vector<vector<int>> v;

int main() {
    fastio();
    
    cin >> N >> T;
    v.resize(N + 1, vector<int>(2));
    dp.resize(N + 1, vector<int>(T + 1));
    for (int i = 1; i <= N; ++i) cin >> v[i][0] >> v[i][1];
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= T; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i][0]) dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i][0]] + v[i][1]);
        }
    }

    cout << dp[N][T];
    return 0;
}
