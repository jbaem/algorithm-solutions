#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>

using namespace std;

int main() {
    fastio();

    int N; cin >> N;
    for (int i = 1; i <= 9; ++i)
		cout << N << " * " << i << " = " << N * i << '\n';
    
    return 0;
}