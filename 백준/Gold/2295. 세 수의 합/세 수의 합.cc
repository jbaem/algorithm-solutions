#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int N, res = 0;
vector<int> v;
unordered_map<int, int> um;

int main() {
    fastio();

    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    
    for (int y = N - 1; y >= 0; --y) {
        for (int z = y; z < N; ++z) {
            um[v[z] - v[y]] = v[z];
        }
        for (int x = 0; x <= y; ++x) {
            res = max(res, um[v[x] + v[y]]);
        }
    }
    cout << res;
    return 0;
}