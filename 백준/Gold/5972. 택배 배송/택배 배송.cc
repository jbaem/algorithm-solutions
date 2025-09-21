#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

typedef pair<int, int> pii;

int N, M;
vector<int> v;
vector<vector<pii>> road;

int main() {
    fastio();

    cin >> N >> M;
    v.resize(N + 1, INF);
    road.resize(N + 1, vector<pii>());
    for (int i = 0; i < M; ++i) {
        int a, b, c; cin >> a >> b >> c;
        road[a].push_back({ b,c });
        road[b].push_back({ a,c });
    }

    v[1] = 0;
    priority_queue<pii> pq;
    pq.push({ -v[1], 1 });
    while (!pq.empty()) {
        auto curr = pq.top(); pq.pop();
        int pos = curr.second, dist = -curr.first;
        if (v[pos] < dist) continue;

        for (auto p : road[pos]) {
            int next = p.first, addDist = p.second;

            if (v[next] <= dist + addDist) continue;

            v[next] = dist + addDist;
            pq.push({ -v[next],next});
        }
    }
    cout << v[N];
    return 0;
}