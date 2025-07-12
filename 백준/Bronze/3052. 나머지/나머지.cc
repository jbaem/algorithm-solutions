#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> us;

int main() {
    fastio();
   
    for (int i = 0; i < 10; ++i) {
        int A; cin >> A;
        us.insert(A % 42);
    }
    cout << us.size();
    return 0;
}