#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef pair<int, string> pis;

int P, M, L;
string N;
vector<vector<pis>> v;

bool cmp(pis p1, pis p2) {
    return p1.second.compare(p2.second) < 0;
}

int main() {
    fastio();
    
    cin >> P >> M;
    while (P-- > 0) {
        cin >> L >> N;
        if (v.size() == 0) {
            v.push_back(vector<pis>());
            v[0].push_back({L,N});
            continue;
        }
        bool flag = true;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i].size() == M
                || L < v[i][0].first - 10
                || L > v[i][0].first + 10) {
                continue;
            }
            v[i].push_back({ L,N });
            flag = false;
            break;
        }
        if (flag) {
            v.push_back(vector<pis>());
            v[v.size() - 1].push_back({ L,N });
            continue;
        }
    }

    for (int i = 0; i < v.size(); ++i) {
        cout << (v[i].size() == M ? "Started!\n" : "Waiting!\n");
        sort(v[i].begin(), v[i].end(), cmp);
        for (int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j].first << " " << v[i][j].second << "\n";
        }
    }
    return 0;
}