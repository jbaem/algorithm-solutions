#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int N, tmp;
stack<pair<int, int>> st;

int main() {
    fastio();

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> tmp;

        while (!st.empty() && st.top().first < tmp) {
            st.pop();
        }
        cout << (st.empty() ? 0 : st.top().second) << " ";
        st.push({ tmp, i });
    }
    return 0;
}