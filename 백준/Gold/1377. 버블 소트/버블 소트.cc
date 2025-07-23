#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int N, a;
map<int, vector<int>> m;

int main() {
    fastio();

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> a;
        if (m.find(-a) == m.end()) m[-a].resize(2);

        m[-a][0] = max(m[-a][0], i);
        m[-a][1]++;
    }

    int idx = N, res = 0;
    for (auto iter : m) {
        res = max(res, iter.second[0] - idx);
        idx -= iter.second[1];
    }
    cout << res + 1;
    return 0;
}