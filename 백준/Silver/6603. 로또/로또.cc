#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> v, res;
const int M = 6;

void dfs(int idx) {
    if (res.size() == M) {
        for (int i = 0; i < M; ++i) cout << res[i] << " ";
        cout << "\n";
    }

    for (int i = idx + 1; i < N; ++i) {
        res.push_back(v[i]);
        dfs(i);
        res.pop_back();
    }
}

int main() {
    fastio();

    res.reserve(M);
    while (cin >> N)
    {
        if (N == 0) break;
        v.resize(N);
        for (int i = 0; i < N; ++i) cin >> v[i];

        dfs(-1);

        cout << "\n";
        v.clear();
    }
    return 0;
}