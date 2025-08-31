#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 987654321

using namespace std;

int N, M;
vector<vector<int>> v, dp;

int dy[3] = { -1, 0, -1 };
int dx[3] = { 0, -1, -1 };

bool is_outside(int y, int x) {
    return y < 0 || x < 0 || y >= N || x >= M;
}


int main() {
    fastio();

    cin >> N >> M;
    v.resize(N, vector<int>(M));
    dp.resize(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> v[i][j];
        }
    }

    dp[0][0] = v[0][0];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < 3; ++k) {
                int by = i + dy[k], bx = j + dx[k];
                if (is_outside(by, bx)) continue;

                dp[i][j] = max(dp[i][j], dp[by][bx] + v[i][j]);
            }
        }
    }

    cout << dp[N - 1][M - 1];
    return 0;
}