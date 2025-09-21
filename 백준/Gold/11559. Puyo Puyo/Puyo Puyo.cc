#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N = 12, M = 6, result = 0;
vector<vector<char>> v(N, vector<char>(M));
vector<vector<bool>> visited(N, vector<bool>(M, false));
queue<pair<int, int>> q;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

bool isOutside(int y, int x, char ch) {
    return y < 0 || x < 0 || y >= N || x >= M 
        || v[y][x] == '.' || v[y][x] != ch || visited[y][x];
}

void bombOne(int y, int x) {
    q.push({ y,x });
    visited[y][x] = true;

    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i], nx = x + dx[i];
        if (isOutside(ny, nx, v[y][x])) continue;
        bombOne(ny, nx);
    }
}

bool bombAll() {
    bool result = false;
    visited.assign(N, vector<bool>(M, false));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (v[i][j] == '.' || visited[i][j]) continue;

            bombOne(i, j);
            bool bIsBomb = q.size() >= 4;
            result |= bIsBomb;

            while (!q.empty()) {
                auto curr = q.front(); q.pop();
                if (!bIsBomb) continue;
                v[curr.first][curr.second] = '.';
            }
        }
    }
    return result;
}

void moveAll() {
    for (int i = N - 1; i >= 0; --i) {
        for (int j = 0; j < M; ++j) {
            if (v[i][j] == '.') continue;
            
            int ny = i + 1;
            while(ny < N && v[ny][j] == '.') {
                ny++;
            }
            if (--ny == i) continue;
            v[ny][j] = v[i][j];
            v[i][j] = '.';
        }
    }
}

int main() {
    fastio();

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> v[i][j];
        }
    }
    
    while (true) {
        if (!bombAll()) break;
        moveAll();
        result++;
    }
    cout << result;
    return 0;
}