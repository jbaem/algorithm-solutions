#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, arr[6];

int main() {
    fastio();
    
    cin >> T;
    while (T-- > 0) {
        for (int i = 0; i < 6; ++i) cin >> arr[i];
        
        long long xSqr = (arr[0] - arr[3]) * (arr[0] - arr[3]);
        long long ySqr = (arr[1] - arr[4]) * (arr[1] - arr[4]);
        long long dist = xSqr + ySqr;

        if (dist == 0 && arr[2] == arr[5]) {
            cout << -1 << "\n";
        }
        else if ((arr[2] - arr[5]) * (arr[2] - arr[5]) == dist
              || (arr[2] + arr[5]) * (arr[2] + arr[5]) == dist) {
            cout << 1 << "\n";
        }
        else if ((arr[2] - arr[5]) * (arr[2] - arr[5]) < dist
              && (arr[2] + arr[5]) * (arr[2] + arr[5]) > dist) {
            cout << 2 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }
    
    return 0;
}
