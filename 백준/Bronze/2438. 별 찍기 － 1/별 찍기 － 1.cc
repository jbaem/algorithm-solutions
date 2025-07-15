#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <string>

using namespace std;

int N;
string res;

int main() {
    fastio();

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= i; ++j) res += "*";
        res += "\n";
    }
    cout << res;
    return 0;
}