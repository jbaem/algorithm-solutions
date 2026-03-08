#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#define MOD 1000000000

using namespace std;

int N;
vector<int> dp{ 0, 0, 1, 2 };

int main() {
    fastio();

    cin >> N;
    dp.resize(N + 1);
    for (int i = 4; i <= N; ++i) {
        long long tmp = (long long)(i - 1) * (dp[i - 1] + dp[i - 2]) % MOD;
        dp[i] = tmp;
    }
    cout << dp[N];
    return 0;
}