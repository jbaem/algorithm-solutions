#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T>
using vv = vector<vector<T>>;

int N, M, K, ans;

vv<int> fillKPrefixSum(vv<bool>& v, bool bIsStartWithBlack) {
    vv<int> res(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; ++i) {
        bool bIsBlack = i % 2 == 1 ? bIsStartWithBlack : !bIsStartWithBlack;
        for (int j = 1; j <= M; ++j) {
            res[i][j] = res[i - 1][j] + res[i][j - 1] - res[i - 1][j - 1];
            if (v[i][j] != bIsBlack) ++res[i][j];
			bIsBlack = !bIsBlack;
        }
    }
    return res;
}

int countChanges(const vv<int>& v) { 
    int res = N * M;
    for (int i = K; i <= N; ++i) {
        for (int j = K; j <= M; ++j) {
            int sum = v[i][j] - v[i - K][j] - v[i][j - K] + v[i - K][j - K];
            res = min(res, sum);
        }
    }
    return res;
}

int main() {
    fastio();

    cin >> N >> M >> K;
    vv<bool> v(N + 1, vector<bool>(M + 1));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            char tmp; cin >> tmp;
            v[i][j] = tmp == 'B';
        }
    }

    vv<int> vB = fillKPrefixSum(v, true);
    vv<int> vW = fillKPrefixSum(v, false);

    ans = N * M;
    ans = min(ans, countChanges(vB));
    ans = min(ans, countChanges(vW));
    cout << ans;
    return 0;
}