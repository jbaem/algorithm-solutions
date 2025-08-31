#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;

int main() {
    fastio();

    cin >> N;
    queue<long long> q;
    
    for(int i = 0; i < 10; ++i) q.push(i);
    while(!q.empty()) {
        long long curr = q.front(); q.pop();
        int last = curr % 10;
        if(N-- == 0) {
            cout << curr;
            return 0;
        }

        curr *= 10;
        for(int i = 0; i < last; ++i) {
            q.push(curr + i);
        }
    }
    cout << -1;
    return 0;
}