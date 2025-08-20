#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 987654321

using namespace std;

int main() {
    fastio();

    int T; cin >> T;
    while (T-- > 0) {
        int N, W; cin >> N >> W;
        vector<vector<int>> v(2, vector<int>(N + 1));
        // [0:seq, 1:첫번째, 2:현재] // [0:없음, 1:위가로선, 2:아래가로선, 3:위아래가로선, 4:세로선]
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(5, vector<int>(5, MAX)));

        for (int i = 0; i < 2 * N; ++i) {
            cin >> v[i / N][i % N];
        }
        v[0][N] = v[0][0];
        v[1][N] = v[1][0];

        if (N == 1) {
            cout << (v[0][0] + v[1][0] <= W ? 1 : 2) << "\n";
            continue;
        }

        for (int i = 0; i < 5; ++i) {
            dp[0][i][i] = 0;
        }
        
        for (int seq = 1; seq <= N; ++seq) {
            for (int fir = 0; fir < 5; ++fir) {
                auto pre = dp[seq - 1][fir];

                dp[seq][fir][0] = min({ pre[0], pre[1], pre[2], pre[3], pre[4] }) + 2;

                if (v[0][seq - 1] + v[0][seq] <= W) {
                    dp[seq][fir][1] = min({ pre[0], pre[2] }) + 1;
                }
                if (v[1][seq - 1] + v[1][seq] <= W) {
                    dp[seq][fir][2] = min({ pre[0], pre[1] }) + 1;
                }
                if (v[0][seq - 1] + v[0][seq] <= W && v[1][seq - 1] + v[1][seq] <= W) {
                    dp[seq][fir][3] = min({ pre[0] });
                }
                if (v[0][seq] + v[1][seq] <= W) {
                    dp[seq][fir][4] = min({ pre[0], pre[1], pre[2], pre[3], pre[4] }) + 1;
                }
                
                for (int i = 0; i < 5; ++i) dp[seq][fir][i] = min(dp[seq][fir][i], MAX);

            }
        }

        int res = MAX;
        for (int i = 0; i < 5; ++i) res = min(res, dp[N][i][i]);
        cout << res << "\n";
    }
    return 0;
}