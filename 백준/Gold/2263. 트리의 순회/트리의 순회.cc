#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int N, rootVal;
vector<int> v1, v2; //v1:inOrder, v2:postOrder
unordered_map<int, int> um;

void tree_info(int l1, int r1, int l2, int r2) {
    if (l1 > r1 || l2 > r2) return;
    
    int root = v2[r2];
    cout << root << " ";
    if (l2 == r2) return;
    
    int tgtIdx = um[root];
    int leftSize = tgtIdx - 1 - l1;
    
    tree_info(l1, tgtIdx - 1, l2, l2 + leftSize);
    tree_info(tgtIdx + 1, r1, l2 + leftSize + 1, r2 - 1);
    return;
}

int main() {
    fastio();
    
    cin >> N;
    v1.resize(N);
    v2.resize(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> v1[i];
        um[v1[i]] = i;
    }
    for (int i = 0; i < N; ++i) {
        cin >> v2[i];
    }
    tree_info(0, N - 1, 0, N - 1);
    return 0;
}