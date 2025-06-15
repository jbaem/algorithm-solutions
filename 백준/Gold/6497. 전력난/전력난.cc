#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int M, N, x, y, z;
vector<int> uf;

int uf_find(int a) {
    if (uf[a] == a) return a;

    return uf[a] = uf_find(uf[a]);
}

void uf_union(int a, int b) {
    int ua = uf_find(a);
    int ub = uf_find(b);

    uf[ua] = ub;
}

int main() {
    fastio();

    while (true) {
        int res = 0, cnt = 0;
        priority_queue<vector<int>> pq;
        
        cin >> M >> N;
        if (M == 0 && N == 0) break;

        uf.resize(M);
        for (int i = 0; i < M; ++i) uf[i] = i;

        for (int i = 0; i < N; ++i) {
            cin >> x >> y >> z;
            res += z;
            pq.push(vector<int>{-z, x, y});
        }

        while (cnt < M - 1) {
            auto curr = pq.top(); pq.pop();

            if (uf_find(curr[1]) == uf_find(curr[2])) continue;

            uf_union(curr[1], curr[2]);
            cnt++;
            res += curr[0];
        }
        cout << res << "\n";
    }
    return 0;
}