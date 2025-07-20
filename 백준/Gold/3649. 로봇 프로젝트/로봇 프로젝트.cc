#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int X, N;
vector<int> v;

void find_block() {
    int left = 0, right = N - 1;
    while (left < right) {
        int tmp = v[left] + v[right];
        if (tmp == X) {
            cout << "yes " << v[left] << " " << v[right] << "\n";
            return;
        }
        if (tmp > X) right--;
        else left++;
    }
    cout << "danger\n";
}

int main() {
    fastio();

    while (cin >> X >> N) {
        X *= 10000000;
        v.resize(N);
        for (int i = 0; i < N; ++i) cin >> v[i];
        sort(v.begin(), v.end());

        find_block();
    }
    return 0;
}