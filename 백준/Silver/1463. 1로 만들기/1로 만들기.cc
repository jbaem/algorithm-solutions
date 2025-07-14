#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321

using namespace std;

int N;
vector<int> v;

int main() {
    fastio();

    cin >> N;
    v.resize(N + 1, INF);
    v[1] = 0;
    for (int i = 2; i <= N; ++i) {
        if (i % 3 == 0) v[i] = min(v[i], v[i / 3] + 1);
        if (i % 2 == 0) v[i] = min(v[i], v[i / 2] + 1);
        v[i] = min(v[i], v[i - 1] + 1);
    }
    cout << v[N];
    return 0;
}