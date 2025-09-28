#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <climits>


using namespace std;

int K, N;
vector<int> v;
set<int> s;

int main() {
    fastio();

    cin >> K >> N;
    for (int i = 0; i < K; ++i) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
        s.insert(tmp);
    }

    int curr;
    for (int i = 0; i < N; ++i) {
        curr = *s.begin();
        s.erase(curr);

        for (int n : v) {
            long long next = (long long)curr * n;
            if (next >= INT_MAX) continue;
            s.insert(next);
            if (curr % n == 0) break;
        }
    }
    cout << curr;
    return 0;
}