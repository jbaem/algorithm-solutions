#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N, arr[3];
vector<vector<vector<int>>> dp;
int dmg[6][3] = {
    {9, 3, 1}, {3, 9, 1},
    {9, 1, 3}, {3, 1, 9},
    {1, 9, 3}, {1, 3, 9}
};

int findCount(int curr[3]) {
	if (dp[curr[0]][curr[1]][curr[2]] != INT_MAX) 
        return dp[curr[0]][curr[1]][curr[2]];

    int cnt = 0;
    switch (N) {
    case 1: cnt = 1; break;
    case 2: cnt = 2; break;
    case 3: cnt = 6; break;
    }
    for (int i = 0; i < cnt; ++i) {
        int next[3];
        for (int j = 0; j < 3; ++j) {
			next[j] = max(0, curr[j] - dmg[i][j]);
        }
        dp[curr[0]][curr[1]][curr[2]] = min(
            dp[curr[0]][curr[1]][curr[2]], 
            findCount(next) + 1
        );
    }
	return dp[curr[0]][curr[1]][curr[2]];
}

int main() {
    fastio();
    
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    dp.assign(arr[0] + 1,
        vector<vector<int>>(arr[1] + 1,
            vector<int>(arr[2] + 1, INT_MAX)));
    
    dp[0][0][0] = 0;
    cout << findCount(arr) << "\n";
    return 0;
}