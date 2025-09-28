#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int T, a, b, d = 0;

int main() {
    fastio();

    cin >> T;
    while (T-- > 0)
    {
        cin >> a >> b;
        d = b - a;

        int srd = sqrt(d);
        int srds = srd * srd;
        int res = 2 * srd - 1;
        if (d > srds) res++;
        if (d > srds + srd) res++;
        cout << res << "\n";
    }
    return 0;
}