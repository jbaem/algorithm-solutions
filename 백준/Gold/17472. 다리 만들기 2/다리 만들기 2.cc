#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, M, islandNum = 0, res = 0;
vector<vector<int>> v, bridges; //len,y,x
vector<int> uf;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

bool is_outside(int y, int x) {
    return y < 0 || x < 0 || y >= N || x >= M;
}

void make_island(int y, int x, int num) {
    queue<pii> q;
    q.push({ y,x });
    v[y][x] = num;

    while (!q.empty()) {
        auto curr = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int ny = curr.first + dy[i], nx = curr.second + dx[i];
            if (is_outside(ny, nx) || v[ny][nx] >= 0) continue;

            q.push({ ny, nx });
            v[ny][nx] = num;
        }
    }
}

void make_bridge() {
    //Horizontal
    for (int i = 0; i < N; ++i) {
        int startNum = 0, startIdx = 0;

        for (int j = 0; j < M; ++j) {
            if (v[i][j] > 0) {
                if (startNum != 0 && startNum != v[i][j]) {
                    bridges.push_back({ j - startIdx - 1, startNum, v[i][j] });
                }
                startNum = v[i][j];
                startIdx = j;
            }
        }
    }
    //Vertical
    for (int j = 0; j < M; ++j) {
        int startNum = 0, startIdx = 0;

        for (int i = 0; i < N; ++i) {
            if (v[i][j] > 0) {
                if (startNum != 0 && startNum != v[i][j]) {
                    bridges.push_back({ i - startIdx - 1, startNum, v[i][j] });
                }
                startNum = v[i][j];
                startIdx = i;
            }
        }
    }
    sort(bridges.begin(), bridges.end());
}

int union_find(int a) {
    if (uf[a] == a) return a;
    return uf[a] = union_find(uf[a]);
}

void union_set(int a, int b) {
    int ua = union_find(a);
    int ub = union_find(b);
    if (ua > ub) {
        uf[ua] = ub;
    }
    else {
        uf[ub] = ua;
    }
}

void kruskal() {
    uf.resize(islandNum + 1);
    for (int i = 1; i <= islandNum; ++i) uf[i] = i;

    for (auto bridge : bridges) {
        if (bridge[0] < 2) continue;

        if (union_find(bridge[1]) == union_find(bridge[2])) continue;

        union_set(bridge[1], bridge[2]);
        res += bridge[0];
    }
}

int main() {
    fastio();

    cin >> N >> M;
    v.resize(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> v[i][j];
            v[i][j] = -v[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (v[i][j] < 0) {
                make_island(i, j, ++islandNum);
            }
        }
    }

    make_bridge();
    kruskal();

    for (int i = 1; i <= islandNum; ++i) {
        if (union_find(i) != 1) {
            cout << -1;
            return 0;
        }
    }
    cout << res;
    return 0;
}