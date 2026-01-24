#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int N, res = 0;
vector<vector<int>> v, v2;
set<int> s;

int findLen(int a, int b) {
    return abs(a - b) - 1;
}

int main() {
    fastio();

    cin >> N;
    v.resize(N, vector<int>(2));
    for (int i = 0; i < N; ++i) {
        cin >> v[i][0];
        v[i][1] = i;
        s.insert(i);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < N; ++i) {
        res = max(res, v[i][0] * findLen(v[i][1], *s.begin()));
        res = max(res, v[i][0] * findLen(v[i][1], *s.rbegin()));
        s.erase(v[i][1]);
    }

    cout << res;
    return 0;
}

