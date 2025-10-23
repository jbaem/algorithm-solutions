#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int N, arr[501], dp[501];
vector<int> pre[501];

int findCount(int n) {
    if (dp[n] != 0) return dp[n];
    if (pre[n].empty()) {
        dp[n] = arr[n];
        return arr[n];
    }

    for (auto num : pre[n]) {
        dp[n] = max(dp[n], findCount(num));
    }
    dp[n] += arr[n];
	return dp[n];
}

int main() {
    fastio();

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        int tmp;
        while (cin >> tmp) {
            if (tmp == -1) break;
            pre[i].push_back(tmp);
        }
    }
    
    for (int i = 1; i <= N; ++i) {
        cout << findCount(i) << "\n";
    }
    return 0;
}