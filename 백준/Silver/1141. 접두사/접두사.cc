#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int N;
unordered_set<string> us;
unordered_set<string> usPrefix;

void insert_word(string s) {
    us.insert(s);
    for (int i = 1; i <= s.size(); ++i) {
        usPrefix.insert(s.substr(0, i));
    }
}

int main() {
    fastio();

    cin >> N;
    for (int i = 0; i < N; ++i) {
        string tmp; cin >> tmp;

        if (usPrefix.find(tmp) != usPrefix.end()) continue;

        for (int j = 1; j <= tmp.size(); ++j) {
            string subTmp = tmp.substr(0, j);
            if (us.find(subTmp) != us.end()) {
                us.erase(subTmp);
                break;
            }
        }

        insert_word(tmp);
    }
    cout << us.size();
    return 0;
}