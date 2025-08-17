#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000001

using namespace std;

int N, last = MAX;
vector<vector<int>> v;

bool cmp(vector<int> o1, vector<int> o2) {
    if (o1[1] == o2[1]) return o1[0] > o2[0];
    return o1[1] > o2[1];
}

int main() {
    fastio();

    cin >> N;
    v.resize(N, vector<int>(2));
    for (int i = 0; i < N; ++i) cin >> v[i][0] >> v[i][1];
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; ++i) {
        if (last > v[i][1]) last = v[i][1];
        last -= v[i][0];
    }
    cout << (last < 0 ? -1 : last);
    return 0;
}