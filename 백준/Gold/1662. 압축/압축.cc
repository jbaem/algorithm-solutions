#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

string str;

int recursion(int start, int end) {
    int nextStart, cnt = 0, ret = 0;
    for (int i = start + 1; i < end; ++i) {
        if (str[i] == '(') {
            if (cnt++ == 0) {
                nextStart = i;
            }
        }
        else if (str[i] == ')') {
            if (--cnt == 0) {
                --ret += ((str[nextStart - 1] - '0') * recursion(nextStart, i));
            }
        }
        else {
            if(cnt == 0) ret++;
        }
    }
    return ret;
}

int main() {
    fastio();

    cin >> str;
    cout << recursion(-1, str.length());
    return 0;
}