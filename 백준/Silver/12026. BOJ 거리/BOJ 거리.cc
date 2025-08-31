#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 987654321

using namespace std;

int N;
vector<char> ch;
vector<vector<int>> v, dp; //0:B, 1:O, 2:J

int match_index(char c) {
    if (c == 'B') return 0;
    if (c == 'O') return 1;
    return 2;
}

int main() {
    fastio();

    cin >> N;
    ch.resize(N);
    v.resize(3, vector<int>());
    dp.resize(N, vector<int>(3, MAX));
    for (int i = 0; i < N; ++i) {
        cin >> ch[i];
        int idx = match_index(ch[i]);
        v[idx].push_back(i);
    }

    dp[0][0] = 0;
    for (int i = 1; i < N; ++i) {
        int j = match_index(ch[i]);
        int bj = (j + 2) % 3;
        for (int k = 0; k < v[bj].size(); ++k) {
            if (v[bj][k] >= i) break;
            int bi = v[bj][k];

            dp[i][j] = min(dp[i][j], dp[bi][bj] + (i - bi) * (i - bi));
        }
    }

    int idx = match_index(ch[N - 1]);
    cout << (dp[N - 1][idx] == MAX ? -1 : dp[N - 1][idx]);
    return 0;
}