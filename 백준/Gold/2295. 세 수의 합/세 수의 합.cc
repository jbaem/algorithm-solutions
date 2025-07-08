#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int N, res = 0;
vector<int> v;
unordered_set<int> us;
unordered_map<int, int> um;

int main() {
    fastio();

    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; ++i) cin >> v[i];
    sort(v.begin(), v.end());

    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            us.insert(v[j] + v[i]);
            um.insert({ v[j] - v[i], v[j] });
        }
    }
    for (int target : us) {
        res = max(res, um[target]);    
    }
    cout << res;
    return 0;
}