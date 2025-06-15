#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

struct Position {
    int y, x, cnt;
    Position(int y, int x, int c) : y(y), x(x), cnt(c) {}
};

struct cmp {
    bool operator()(Position o1, Position o2) {
        return o1.cnt > o2.cnt;
    }
};

int N, M, X1, Y1, X2, Y2;
vector<vector<char>> v;
vector<vector<int>> visited;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool is_valid(int y, int x) {
    return y >= 1 && x >= 1 && y <= N && x <= M;
}

void find_criminal() {
    int maxNum = INF;
    priority_queue<Position, vector<Position>, cmp> pq;
    
    pq.push(Position(Y1, X1, 0));
    visited[Y1][X1] = 0;

    while (!pq.empty()) {
        auto curr = pq.top(); pq.pop();
        if (curr.y == Y2 && curr.x == X2) {
            maxNum = curr.cnt;
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int ny = curr.y + dy[i], nx = curr.x + dx[i];
            if (!is_valid(ny, nx)) continue;

            int nc = curr.cnt + (v[ny][nx] == '0' ? 0 : 1);
            if (visited[ny][nx] <= nc) continue;

            pq.push(Position(ny, nx, nc));
            visited[ny][nx] = nc;
        }
    }
}


int main() {
    fastio();
    
    cin >> N >> M >> Y1 >> X1 >> Y2 >> X2;
    v.resize(N + 1, vector<char>(M + 1));
    visited.resize(N + 1, vector<int>(M + 1, INF));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> v[i][j];
        }
    }
    find_criminal();
    cout << visited[Y2][X2];
    return 0;
}