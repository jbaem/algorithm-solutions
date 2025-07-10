#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, tmp, res = 0, maxAdd;
bool grid[10][10], subtract[20]; // 1 <= y-x+10 <= 19

void play(int prev, int cnt) {
    if (maxAdd - prev + cnt <= res) return;
    if (prev == maxAdd) {
        res = max(res, cnt);
        return;
    }

    int curr = prev + 1;
    for (int r = 0; r <= curr; ++r) {
        int c = curr - r;
        if (r >= N || c >= N) continue;

        int idx = r - c + 10;
        if (!subtract[idx] && grid[r][c]) {
            subtract[idx] = true;
            play(curr, cnt + 1);
            subtract[idx] = false;
        }
    }
    play(curr, cnt);
}

int main() {
    fastio();
    
    cin >> N;
    maxAdd = N + N - 2;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }
    play(-1, 0);
    cout << res;
    return 0;
}