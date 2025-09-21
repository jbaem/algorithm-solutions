#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, R, Q;
vector<vector<int>> v, v2; //v:양방향, v2:단방향
vector<int> res;

void make_tree(int root) {
    vector<bool> visited(N + 1);

    queue<int> q;
    q.push(root);
    visited[root] = true;

    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int next : v[curr]) {
            if (visited[next]) continue;

            v2[curr].push_back(next);
            q.push(next);
            visited[next] = true;
        }
    }
}

int count_subtree_nodes(int root) {
    if (res[root] > 0) return res[root];

    int ret = 1;
    for (int child : v2[root]) {
        ret += count_subtree_nodes(child);
    }
    return res[root] = ret;
}

int main() {
    fastio();

    cin >> N >> R >> Q;
    v.resize(N + 1, vector<int>());
    v2.resize(N + 1, vector<int>());
    res.resize(N + 1);

    for (int i = 0; i < N - 1; ++i) {
        int U, V; cin >> U >> V;
        v[U].push_back(V);
        v[V].push_back(U);
    }

    make_tree(R);
    for (int i = 0; i < Q; ++i) {
        int query; cin >> query;
        cout << count_subtree_nodes(query) << "\n";
    }
    return 0;
}