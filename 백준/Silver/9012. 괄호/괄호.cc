#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int T;
string str;

bool check_VPS(string s) {
    stack<char> st;
    for (char ch : s) {
        if (st.empty() || ch== '(') {
            st.push(ch);
            continue;
        }
        if (st.top() == '(') {
            st.pop();
        }
        else {
            return false;
        }
    }
    return st.empty();
}

int main() {
    fastio();
    
    cin >> T;
    while (T-- > 0) {
        cin >> str;
        cout << (check_VPS(str) ? "YES\n" : "NO\n");
    }

    return 0;
}