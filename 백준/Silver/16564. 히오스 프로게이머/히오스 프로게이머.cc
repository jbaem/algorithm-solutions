#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int N, K;
map<int, int> m;

int main() {
    fastio();

    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        int tmp; cin >> tmp;
        m[tmp]++;
    }
    while (K > 0) {
        int key1 = m.begin()->first, val1 = m.begin()->second;
        m.erase(m.begin());

        if (m.empty()) {
            key1 += K / val1;
            m[key1] = val1;
            break;
        }

        int key2 = m.begin()->first;
        int dist = key2 - key1;
        
        if (dist * val1 <= K) {
            m[key2] += val1;
            K -= dist * val1;
        }
        else {
            key1 += K / val1;
            m[key1] = val1;
            break;
        }
    }
    cout << m.begin()->first;
    return 0;
}