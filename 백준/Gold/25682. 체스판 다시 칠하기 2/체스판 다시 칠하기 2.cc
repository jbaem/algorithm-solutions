#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T>
using vv = vector<vector<T>>;

int N, M, K, ans;

vv<int> fillKPrefixSum(vv<bool>& v, bool bIsStartWithBlack) { // row processing
    vv<int> res(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		bool bIsBlack = i % 2 == 0 ? bIsStartWithBlack : !bIsStartWithBlack;
        int cnt = 0;    
        for (int j = 0; j < M; ++j) {
			bool bIsRemoveBlack = K % 2 == 0 ? bIsBlack : !bIsBlack;
            if (v[i][j] != bIsBlack) ++cnt;
            if (j >= K && v[i][j - K] != bIsRemoveBlack) --cnt;
            res[i][j] = cnt;
            bIsBlack = !bIsBlack;
        }
    }    
    return res;
}

int countChanges(const vv<int>& v) { // column processing
    int res = N * M;
    for (int j = K - 1; j < M; ++j) {
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += v[i][j];
            if (i < K - 1) continue;
            if (i >= K) sum -= v[i - K][j];
            res = min(res, sum);
        }
    }
    return res;
}

int main() {
    fastio();

    cin >> N >> M >> K;
    vv<bool> v(N, vector<bool>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
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