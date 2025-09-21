#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

typedef pair<long long, int> pli; //dist, num
typedef pair<int, long long> pil; //num, dist

int N, M, K;
vector<vector<pil>> v;
vector<long long> visited;

int main() {
    fastio();

    cin >> N >> M >> K;
    v.resize(N + 1, vector<pil>());
    visited.resize(N + 1, LLONG_MAX);
    for (int i = 0; i < M; ++i) {
        int U, V, C; cin >> U >> V >> C;
        v[V].push_back({ U,C });
    }

    priority_queue<pli> pq;
    for (int i = 0; i < K; ++i) {
        int n; cin >> n;
        pq.push({ 0, n });
        visited[n] = 0;
    }

    while (!pq.empty()) {
        pli curr = pq.top(); pq.pop();
        long long currDist = -curr.first;
        int currNum = curr.second;

        if (visited[currNum] < currDist) continue;

        for (auto next : v[currNum]) {
            long long nextDist = currDist + next.second;
            int nextNum = next.first;

            if (visited[nextNum] > nextDist) {
                pq.push({ -nextDist, nextNum });
                visited[nextNum] = nextDist;
            }
        }
    }

    int resNum = 0;
    long long resDist = 0;
    for (int i = 1; i <= N; ++i) {
        if (visited[i] != LLONG_MAX && resDist < visited[i]) {
            resNum = i;
            resDist = visited[i];
        }
    }
    cout << resNum << "\n";
    cout << resDist << "\n";
    return 0;
}