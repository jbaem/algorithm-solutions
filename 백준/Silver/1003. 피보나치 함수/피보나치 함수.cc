#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, N, arr[41][2] = { {1,0}, {0,1}, };

int main() {
    fastio();
    
for (int i = 2; i <= 40; ++i) {
        arr[i][0] = arr[i - 1][0] + arr[i - 2][0];
        arr[i][1] = arr[i - 1][1] + arr[i - 2][1];
    }

    cin >> T;
    while (T-- > 0) {
        cin >> N;
        cout << arr[N][0] << " " << arr[N][1] << "\n";
    }
    
    return 0;
}
