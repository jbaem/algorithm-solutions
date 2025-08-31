#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 8

using namespace std;

char v[MAX+1][MAX][MAX]; //t,y,x
int dy[9] = { -1,-1,-1, 0, 0, 0, 1, 1, 1 };
int dx[9] = { -1, 0, 1,-1, 0, 1,-1, 0, 1 };

bool is_outside(int t, int y, int x) {
    return t < 0 || y < 0 || x < 0 || t >= MAX + 1 || y >= MAX || x >= MAX;
}

int main() {
    fastio();

    for (int t = 0; t < MAX + 1; ++t) {
        for (int i = 0; i < MAX; ++i) {
            for (int j = 0; j < MAX; ++j) {
                v[t][i][j] = '.';
            }
        }
    }

    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            char tmp; cin >> tmp;
            if (tmp == '#') {
                for (int nt = 0, ny = i; !is_outside(nt, ny, j); ++nt, ++ny) {
                    v[nt][ny][j] = '#';
                }
            }
        }
    }

    queue<vector<int>> q;
    q.push({ 0,7,0 });
    v[0][7][0] = '@';

    while (!q.empty()) {
        vector<int> curr = q.front(); q.pop();

        if (curr[0] == 8) {
            cout << 1;
            return 0;
        }

        for (int i = 0; i < 9; ++i) {
            int ny = curr[1] + dy[i], nx = curr[2] + dx[i];

            if (is_outside(curr[0], ny, nx)) continue;
            
            if (v[curr[0]][ny][nx] == '#'
                || v[curr[0] + 1][ny][nx] == '#'
                || v[curr[0] + 1][ny][nx] == '@')
                continue;

            v[curr[0] + 1][ny][nx] = '@';
            q.push({ curr[0] + 1, ny, nx });
        }
    }
    cout << 0;
    return 0;
}