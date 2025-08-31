#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, res = 0;
vector<vector<int>> v;
vector<vector<bool>> visited;

int dy[4] = { -1,-1,0,0 };
int dx[4] = { -1,0,-1,0 };
int scales[4][4] = { {2,1,1,0},
                     {1,2,0,1},
                     {1,0,2,1},
                     {0,1,1,2} };

bool is_valid(int y, int x, int sc) {
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i], nx = x + dx[i];
        if (scales[sc][i] > 0 
            && (ny < 0 || nx < 0 || visited[ny][nx]))
            return false;
    }
    return true;
}

int make_weapon(int y, int x, int sc) {
    int ret = 0;
    for (int i = 0; i < 4; ++i) {
        if (scales[sc][i] > 0) {
            int ny = y + dy[i], nx = x + dx[i], ns = scales[sc][i];
            visited[ny][nx] = true;
            ret += v[ny][nx] * ns;
        }
    }
    return ret;
}

void destroy_waepon(int y, int x, int sc) {
    for (int i = 0; i < 4; ++i) {
        if (scales[sc][i] > 0) {
            int ny = y + dy[i], nx = x + dx[i];
            visited[ny][nx] = false;
        }
    }
}

void recursion(int num, int count) {
    if (num == N * M) {
        res = max(res, count);
        return;
    }

    int y = num / M, x = num % M;
    if (y == 0 || x == 0) {
        recursion(num + 1, count);
        return;
    }

    for (int sc = 0; sc < 4; ++sc) {
        if (!is_valid(y, x, sc)) continue;
        recursion(num + 1, count + make_weapon(y, x, sc));
        destroy_waepon(y, x, sc);
    }
    recursion(num + 1, count);
}

int main() {
    fastio();

    cin >> N >> M;
    v.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> v[i][j];
        }
    }
    recursion(0, 0);
    cout << res;
    return 0;
}