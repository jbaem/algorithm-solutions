#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N, tmp;
unordered_map<int, int> um;

int main() {
    fastio();

    cin >> N;
    while (N-- > 0) {
        cin >> tmp;
        um[tmp]++;
    }
    cin >> N;
    while (N-- > 0) {
        cin >> tmp;
        cout << um[tmp] << " ";
    }
    return 0;
}