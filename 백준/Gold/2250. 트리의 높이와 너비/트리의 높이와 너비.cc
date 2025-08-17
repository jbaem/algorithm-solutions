#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, cnt = 1, resLevel = 0, resWidth = -1;
vector<vector<int>> v, pos(1);
vector<bool> isChild;

int find_root() {
    for (int i = 1; i <= N; ++i) {
        if (!isChild[i]) return i;
    }
    return -1;
}

void inorder_traversal(int nodeNum, int level) {
    if (nodeNum == -1) return;

    inorder_traversal(v[nodeNum][0], level + 1);

    int curr = cnt++;
    while(pos.size() <= level) pos.push_back(vector<int>());
    pos[level].push_back(curr);
    
    inorder_traversal(v[nodeNum][1], level + 1);
}

void find_max_width() {
    for (int i = 1; i < pos.size(); ++i) {
        int currWidth = pos[i][pos[i].size() - 1] - pos[i][0];

        if (resWidth < currWidth) {
            resLevel = i;
            resWidth = currWidth;
        }
    }
}

int main() {
    fastio();

    cin >> N;
    v.resize(N + 1, vector<int>(2));
    isChild.resize(N + 1);

    for (int i = 0; i < N; ++i) {
        int a, b, c; cin >> a >> b >> c;

        v[a][0] = b;
        v[a][1] = c;

        if(b > 0) isChild[b] = true;
        if(c > 0) isChild[c] = true;
    }

    inorder_traversal(find_root(), 1);

    find_max_width();
    cout << resLevel << " " << resWidth + 1;

    return 0;
}