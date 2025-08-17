#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000001

using namespace std;

int N, cnt = 0;
vector<vector<int>> v;
vector<bool> visited;

void traversal(int n, int depth) {
    visited[n] = true;

    bool flag = false;
    for (int i = 0; i < v[n].size(); ++i) {
        if (visited[v[n][i]]) continue;
        traversal(v[n][i], depth + 1);
        flag = true;
    }
    if(!flag) cnt += depth;
}

int main() {
    fastio();

    cin >> N;
    v.resize(N + 1, vector<int>());
    visited.resize(N + 1);

    for (int i = 1; i <= N - 1; ++i) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    traversal(1, 0);
    cout << (cnt % 2 == 0 ? "No" : "Yes");
    return 0;
}