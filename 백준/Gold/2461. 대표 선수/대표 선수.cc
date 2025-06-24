#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000000001;

using namespace std;

int N, M, res = MAX;
vector<vector<int>> v;
vector<int> classCnt;

int delete_first(int target) {
    while (true) {
        if (classCnt[v[target][1]] <= 1) break;
        classCnt[v[target][1]]--;
        target++;
    }
    return target;
}

int main() {
    fastio();

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            vector<int> v2(2);
            cin >> v2[0];
            v2[1] = i;
            v.push_back(v2);
        }
    }
    sort(v.begin(), v.end());

    classCnt.assign(N, 0);
    int left = 0, right = -1, vSize = v.size();
    while (++right < vSize) {
        classCnt[v[right][1]]++;
        
        bool flag = true;
        for (int i = 0; i < N; ++i) {
            if (classCnt[i] == 0) {
                flag = false;
                break;
            }
        }
        if (!flag) continue;

        left = delete_first(left);
        res = min(res, v[right][0] - v[left][0]);
    }
    cout << res;
    return 0;
}