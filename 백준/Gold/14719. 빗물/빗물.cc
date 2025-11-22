#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int H, W, res = 0;
vector<int> v;

int main() {
    fastio();

	cin >> H >> W;
    v.resize(W, 0);
	for (int i = 0; i < W; i++) cin >> v[i];
	
    for (int i = 1; i < W - 1; ++i) {
        int l = 0, r = 0;
        
        for (int j = 0; j < i; ++j) l = max(l, v[j]);
        for (int j = i + 1; j < W; ++j) r = max(r, v[j]);
        res += max(0, min(l, r) - v[i]);
    }
    cout << res << "\n";
    return 0;
}