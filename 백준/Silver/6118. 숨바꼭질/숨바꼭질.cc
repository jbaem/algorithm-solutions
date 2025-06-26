#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, a, b;
vector<vector<int>> v;
vector<bool> visited;
queue<int> q;

int main() {
    fastio();

    cin >> N >> M;
    v.resize(N + 1, vector<int>());
    visited.resize(N + 1);

    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    q.push(1);
    visited[1] = true;

    int lev = 0;
    while (!q.empty()) {
        int num = 20000;
        
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i) {
            int curr = q.front(); q.pop();
            num = min(num, curr);

            for (int j = 0; j < v[curr].size(); ++j) {
                int next = v[curr][j];
                if (visited[next]) continue;
                
                q.push(next);
                visited[next] = true;
            }
        }
        if (q.empty()) {
            cout << num << " " << lev << " " << qSize;
        }
        lev++;
    }
    return 0;
}