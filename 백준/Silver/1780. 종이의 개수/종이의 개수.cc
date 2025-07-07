#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, res[3];
vector<vector<int>> v;

bool is_all_same(int r1, int c1, int r2, int c2) {
    int target = v[r1][c1];
    for (int i = r1; i < r2; ++i) {
        for (int j = c1; j < c2; ++j) {
            if (v[i][j] != target) return false;
        }
    }
    return true;
}

void divide_conquer(int r1, int c1, int r2, int c2) {
    if (is_all_same(r1, c1, r2, c2)) {
        res[v[r1][c1] + 1]++;
        return;
    }
    int cropSize = (r2 - r1) / 3;
    
    for (int i = r1; i < r2; i += cropSize) {
        for (int j = c1; j < c2; j += cropSize) {
            divide_conquer(i, j, i + cropSize, j + cropSize);
        }
    }
}

int main() {
    fastio();

    cin >> N;
    v.resize(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> v[i][j];
        }
    }

    divide_conquer(0, 0, N, N);

    for (int i = 0; i < 3; ++i) cout << res[i] << "\n";
    return 0;
}