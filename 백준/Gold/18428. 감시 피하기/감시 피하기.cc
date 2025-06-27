#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int N;
vector<string> v[6][6];
vector<pair<int, int>> tPos;
unordered_map<string, bool> checkTable;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void input_value() {
    int sCnt = 1, tCnt = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            string tmp; cin >> tmp;
            if (tmp == "T") {
                v[i][j].push_back(tmp + to_string(tCnt++));
                tPos.push_back({ i,j });
            }
            if (tmp =="S") {
                v[i][j].push_back(tmp + to_string(sCnt++));
            }
        }
    }
}

bool is_outside(int y, int x) {
    return y < 0 || x < 0 || y >= N || x >= N;
}

string add_mark(int y, int x, int dir, string mark) {
    if (is_outside(y, x)) return "-";
    
    if (v[y][x].size() != 0) {
        if (v[y][x][0].size() == 2 && v[y][x][0][0] == 'T') return "-";
        if (v[y][x][0][0] == 'S') {
            checkTable.insert({ mark + v[y][x][0], true });
            return mark + v[y][x][0];
        }
    }
    string next = add_mark(y + dy[dir], x + dx[dir], dir, mark);
    if (next != "-") {
        v[y][x].push_back(next);
    }
    return next;
}

bool check_supervision() {
    for (auto t : tPos) {
        int y = t.first, x = t.second;
        for (int d = 0; d < 4; ++d) {
            int ny = y + dy[d], nx = x + dx[d];
            if (is_outside(ny, nx)) continue;

            if (v[ny][nx].size() != 0 && v[ny][nx][0][0] == 'S') return false;

            add_mark(ny, nx, d, v[y][x][0]);
        }
    }
    return true;
}

bool check_result(int idx, int cnt) {
    if (cnt > 3) {
        for (auto iter : checkTable) {
            if (iter.second) return false;
        }
        return true;
    }

    bool ret = false;
    int bound = N * N;
    vector<string> tmp;

    if (idx > 0) {
        for (auto str : v[idx / N][idx % N]) {
            if (checkTable[str]) {
                tmp.push_back(str);
                checkTable[str] = false;
            }
        }
    }

    for (int curr = idx + 1; curr < bound; curr++) {
        ret |= check_result(curr, cnt + 1);
    }
    
    for (auto str : tmp) {
        checkTable[str] = true;
    }

    return ret;
}


int main() {
    fastio();

    cin >> N;
    input_value();
    

    if (!check_supervision()) {
        cout << "NO";
        return 0;
    }

    cout << (check_result(-1, 0) ? "YES" : "NO");
    return 0;
}