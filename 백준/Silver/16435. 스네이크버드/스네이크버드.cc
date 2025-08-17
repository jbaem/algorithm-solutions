#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, L;
vector<int> v;

int main() {
    fastio();

    cin >> N >> L;
    v.resize(N);
    for (int i = 0; i < N; ++i) cin >> v[i];
    sort(v.begin(), v.end());

    for (int i = 0; i < N; ++i) {
        if (L >= v[i]) L++;
        else break;
    }
    cout << L;
    return 0;
}