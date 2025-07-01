#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int K;
vector<vector<int>> v;

void traversal(int depth) {
    if (depth == K) return;
    
    traversal(depth + 1);
    int tmp; cin >> tmp;
    v[depth].push_back(tmp);
    traversal(depth + 1);
}

int main() {
    fastio();

    cin >> K;
    v.resize(K, vector<int>());
    traversal(0);

    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}