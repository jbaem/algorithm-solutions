#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>

using namespace std;

int N, res = 0;

int main() {
    fastio();

    for (int i = 0; i < 5; ++i) {
        cin >> N;
        res += N * N;
    }
    cout << res % 10;
    return 0;
}