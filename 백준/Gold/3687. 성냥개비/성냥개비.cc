#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

using pic = pair<int, char>;

int T, N;

bool isLower(string& s1, string& s2) {
    if (s1 == "") return false;

    int size1 = s1.size(), size2 = s2.size();
    if (size1 != size2) {
        return size1 < size2;
    }

    for (int i = 0; i < size1; ++i) {
        if (s1[i] == s2[i]) continue;
        return s1[i] < s2[i];
    }
    return false;
}

string minDp[101] = { "0","0","1","7","4","2","6","8","10" };
void fillMinDp() {
    vector<pic> v{ {2,'1'}, {3,'7'}, {4,'4'}, {5,'2'}, {6,'0'}, {7,'8'} };

    for (int i = 9; i < 101; ++i) {
        string tmp = "";
        for (auto pa : v) {
            string s1 = minDp[i - pa.first] + pa.second;
            if (pa.first != 6) {
                string s2 = pa.second + minDp[i - pa.first];
                if (!isLower(s1, s2)) {
                    s1 = s2;
                }
            }

            if (!isLower(tmp, s1)) {
                tmp = s1;
            }
        }
        minDp[i] = tmp;
    }
}

string maxDp[101] = { "0","0","1","7" };
void fillMaxDp() {
    for (int i = 4; i < 101; ++i) {
        maxDp[i] = maxDp[i - 2] + '1';
    }
}

int main() {
    fastio();

    fillMinDp();
    fillMaxDp();

    cin >> T;
    while (T-- > 0) {
        cin >> N;
        cout << minDp[N] << " " << maxDp[N] << "\n";
    }
    return 0;
}