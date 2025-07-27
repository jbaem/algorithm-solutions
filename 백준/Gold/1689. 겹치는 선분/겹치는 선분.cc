#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, s, e;
vector<pii> v;
priority_queue<int, vector<int>, greater<int>> pq;

bool cmp(pii o1, pii o2) {
    if (o1.first == o2.first) {
        return o1.second < o2.second;
    }
    return o1.first < o2.first;
}

int main() {
    fastio();

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> s >> e;
        v.push_back({ s,e });
    }
    sort(v.begin(), v.end(), cmp);
    
    pq.push(v[0].second);
    for (int i = 1; i < N; ++i) {
        if (pq.top() <= v[i].first) {
            pq.pop();
        }
        pq.push(v[i].second);
    }
    cout << pq.size();
    return 0;
}