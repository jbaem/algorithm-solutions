#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N;
vector<vector<char>> v;

string devide(int y1, int x1, int y2, int x2, int sz) {
    string result = "";
    if (sz == 1) {
        result += v[y1][x1];
        return result;
    }

    int nsz = sz / 2;
    string part[4];
    part[0] = devide(y1, x1, y2 - nsz, x2 - nsz, nsz);
    part[1] = devide(y1, x1 + nsz, y2 - nsz, x2, nsz);
    part[2] = devide(y1 + nsz, x1, y2, x2 - nsz, nsz);
    part[3] = devide(y1 + nsz, x1 + nsz, y2, x2, nsz);

    bool flag = part[0] == "0" || part[0] == "1";
    for (int i = 1; i < 4; ++i) {
        if (part[i] != part[i - 1]) {
            flag = false;
        }
    }
    if (flag) return part[0];

    result += "(";
    for (int i = 0; i < 4; ++i) {
        result.append(part[i]);
    }
    result += ")";
    return result;
}

int main() {
    fastio();

    cin >> N;
    v.resize(N, vector<char>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> v[i][j];
        }
    }

    cout << devide(0, 0, N - 1, N - 1, N);
    return 0;
}