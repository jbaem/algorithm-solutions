#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, T, a, b;
vector<int> dp;

int main() {
    fastio();
    
    cin >> N >> T;
    dp.resize(T + 1);
    
    for (int i = 1; i <= N; ++i) {
        cin >> a >> b;
        for (int j = T; j >= a; --j) {
            dp[j] = max({ dp[j], dp[j - 1], dp[j - a] + b });
        }
     }

    cout << dp[T];
    return 0;
}
