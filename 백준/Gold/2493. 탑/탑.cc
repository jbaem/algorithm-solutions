#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> pii;

int N;
vector<int> v, res;
stack<pii> st;

int main() {
    fastio();

    cin >> N;
    v.resize(N + 1);
    res.resize(N + 1);
    for (int i = 1; i <= N; ++i) cin >> v[i];

    for (int i = N; i > 0; --i) {
        while (!st.empty() && st.top().first <= v[i]) {
            res[st.top().second] = i;
            st.pop();
        }
        st.push({ v[i], i });
    }
    for (int i = 1; i <= N; ++i) cout << res[i] << " ";
    return 0;
}