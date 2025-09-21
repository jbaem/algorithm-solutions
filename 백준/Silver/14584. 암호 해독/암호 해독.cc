#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N, atoz = 'z' - 'a' + 1;
string s;
vector<string> vs;

int main() {
    fastio();

    cin >> s >> N;
    vs.resize(N);
    for (int i = 0; i < N; ++i) cin >> vs[i];

    for (int i = 0; i < atoz; ++i) {
        for (int j = 0; j < vs.size(); ++j) {
            if (s.find(vs[j]) != string::npos) {
                cout << s;
                return 0;
            }
        }
        for (int j = 0; j < s.length(); ++j) {
            if (s[j] == 'z') s[j] = 'a';
            else s[j]++;
        }
    }

    return 0;
}