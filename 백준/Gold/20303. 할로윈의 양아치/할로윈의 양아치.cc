#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

typedef pair<int, int> pii;

int N, M, K, a, b;
vector<int> candies, uf;
vector<vector<int>> dp;
vector<pii> grp;
unordered_map<int, vector<int>> um; //<grp, {candy, memCnt}>

bool cmp(pii p1, pii p2) {
    double o1 = (double)p1.first / p1.second;
    double o2 = (double)p2.first / p2.second;

    if (o1 == o2) {
        return p1.second > p2.second;
    }
    return o1 > o2;
}

int find_relation(int n) {
    if (uf[n] == n) return n;
    return uf[n] = find_relation(uf[n]);
}

void union_relation(int n1, int n2) {
    int ufn1 = find_relation(n1);
    int ufn2 = find_relation(n2);
    
    if (ufn1 < ufn2) uf[ufn2] = ufn1;
    else uf[ufn1] = ufn2;
}

int main() {
    fastio();

    cin >> N >> M >> K;
    
    candies.resize(N + 1);
    for (int i = 1; i <= N; ++i) cin >> candies[i];
    for (int i = 0; i <= N; ++i) uf.push_back(i);

    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        union_relation(a, b);
    }

    for (int i = 1; i <= N; ++i) {
        find_relation(i);
        if (um.find(uf[i]) == um.end()) um[uf[i]].resize(2);
        um[uf[i]][0] += candies[i];
        um[uf[i]][1]++;
    }

    for (auto iter : um) {
        grp.push_back({ iter.second[0], iter.second[1] });
    }
    sort(grp.begin(), grp.end(), cmp);
    
    dp.resize(grp.size() + 1, vector<int>(K));
    for (int i = 1; i <= grp.size(); ++i) {
        int candy = grp[i - 1].first, memCnt = grp[i - 1].second;

        for (int j = 0; j < K; ++j) {
            if (j >= memCnt) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - memCnt] + candy);
            else dp[i][j] = dp[i - 1][j];
        }

    }
    cout << dp[grp.size()][K - 1];
    return 0;
}