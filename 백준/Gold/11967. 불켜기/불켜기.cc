#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, M, cnt = 1;

vector<pii> v[101][101];
bool visited[101][101], brightRoom[101][101];
queue<pii> q;

bool is_outside(int x, int y) {
    return x < 1 || y < 1 || x > N || y > N;
}

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };
bool is_valid(int x, int y) {
    bool ret = false;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!is_outside(nx, ny) && visited[nx][ny]) {
            ret = true;
        }
    }
    return ret;
}

int main() {
    fastio();

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int x, y, a, b; cin >> x >> y >> a >> b;
        v[x][y].push_back({ a,b });
    }

    q.push({ 1,1 });
    brightRoom[1][1] = true;

    bool flag = true;
    while (flag && !q.empty()) {
        flag = false;

        int qSize = q.size();
        for (int i = 0; i < qSize; ++i) {
            int x = q.front().first, y = q.front().second;
            q.pop();

            if (!(x == 1 && y == 1) && !is_valid(x, y)) {
                q.push({x, y});
                continue;
            }
            
            visited[x][y] = true;
            flag = true;
            
            for (int j = 0; j < v[x][y].size(); ++j) {
                int nx = v[x][y][j].first, ny = v[x][y][j].second;

                if (!brightRoom[nx][ny]) {
                    brightRoom[nx][ny] = true;
                    q.push({ nx, ny });
                    cnt++;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}