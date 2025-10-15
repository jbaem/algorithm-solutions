#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

using pii = pair<int, int>;

int T, H, W, answer;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

vector<vector<char>> v;
unordered_set<char> keys;
vector<vector<pii>> postpones('z' - 'a' + 1, vector<pii>());
queue<pii> q;

bool isOutside(int y, int x) {
    return y < 0 || y >= H || x < 0 || x >= W;
}

void enqueuePosition(int y, int x) {
    if (isOutside(y, x) || v[y][x] == '*') return;

    if (v[y][x] >= 'A' && v[y][x] <= 'Z') {
        if (keys.find(v[y][x] - 'A' + 'a') == keys.end()) {
            postpones[v[y][x] - 'A'].push_back({ y, x });
            v[y][x] = '*';
            return;
        }
        else {
            q.push({ y,x });
            v[y][x] = '*';
        }
    }

	if (v[y][x] == '$') answer++;

    if (v[y][x] >= 'a' && v[y][x] <= 'z') {
        keys.insert(v[y][x]);
        for (auto postpone : postpones[v[y][x] - 'a']) {
            q.push(postpone);
		}
		postpones[v[y][x] - 'a'].clear();
    }
    
    q.push({ y,x });
    v[y][x] = '*';
}

void reset() {
    keys.clear();
	for (auto& postpone : postpones) postpone.clear();
    while (!q.empty()) q.pop();
}

int main() {
    fastio();

    cin >> T;
    while (T--) {
        cin >> H >> W;

        answer = 0;
        v.assign(H, vector<char>(W, 0));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> v[i][j];

                if (i > 0 && i < H - 1 && j > 0 && j < W - 1)
                    continue;
				
				enqueuePosition(i, j);
            }
        }

        {
            string tmp; cin >> tmp;
            for (auto ch : tmp) {
				if (ch == '0') break;
                keys.insert(ch);
            }
        }

        for (auto key : keys) {
            for (auto postpone : postpones[key - 'a']) {
                q.push(postpone);
            }
            postpones[key - 'a'].clear();
        }

        while (!q.empty()) {
			auto curr = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int ny = curr.first + dy[i], nx = curr.second + dx[i];
                enqueuePosition(ny, nx);
            }
        }
        cout << answer << '\n';
        reset();
    }
    return 0;
}